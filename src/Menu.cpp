#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <limits> // Required for numeric_limits

// Helper function to clear input buffer
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Constructor
Menu::Menu(AuthService& auth, DoctorDatabase& ddb, PatientDatabase& pdb, AppointmentDatabase& adb)
    : authService(auth), doctorDb(ddb), patientDb(pdb), appointmentDb(adb) {}

// Main entry point
void Menu::run() {
    while (true) {
        std::vector<std::string> options = {"Patient Login", "Patient Signup", "Admin Access", "Exit"};
        int choice = getMenuChoice(options, "Main Portal");

        switch (choice) {
            case 0: handlePatientLogin(); break;
            case 1: handlePatientSignup(); break;
            case 2: handleAdminAccess(); break;
            case 3: return; // Exit
        }
    }
}

// --- Core UI Functions ---
void Menu::printInteractiveMenu(const std::vector<std::string>& options, int selected, const std::string& title) {
    system("cls");
    std::cout << "--- " << title << " ---" << std::endl;
    for (int i = 0; i < options.size(); ++i) {
        if (i == selected) {
            std::cout << " >  " << options[i] << std::endl;
        } else {
            std::cout << "   " << options[i] << std::endl;
        }
    }
    std::cout << "\nUse arrow keys to navigate and Enter to select." << std::endl;
}

int Menu::getMenuChoice(const std::vector<std::string>& options, const std::string& title) {
    int selected = 0;
    int input;
    while (true) {
        printInteractiveMenu(options, selected, title);
        input = _getch();
        if (input == 224) { // Arrow keys
            switch (_getch()) {
                case 72: // Up
                    selected = (selected - 1 + options.size()) % options.size();
                    break;
                case 80: // Down
                    selected = (selected + 1) % options.size();
                    break;
            }
        } else if (input == 13) { // Enter
            return selected;
        }
    }
}

// --- Authentication Flows ---
void Menu::handlePatientLogin() {
    system("cls");
    std::cout << "--- Patient Login ---" << std::endl;
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (authService.login(username, password)) {
        loggedInUser = username;
        showPatientDashboard();
    } else {
        std::cout << "Invalid credentials. Press any key to continue...";
        _getch();
    }
}

void Menu::handlePatientSignup() {
    system("cls");
    std::cout << "--- Patient Signup ---" << std::endl;
    std::string username, password;
    std::cout << "Choose Username: ";
    std::cin >> username;
    std::cout << "Choose Password: ";
    std::cin >> password;

    if (authService.signUp(username, password)) {
        std::cout << "Signup successful! Please log in. Press any key to continue...";
    } else {
        std::cout << "Username already exists. Press any key to continue...";
    }
    _getch();
}

void Menu::handleAdminAccess() {
    system("cls");
    std::cout << "--- Admin Access ---" << std::endl;
    std::string password;
    std::cout << "Enter admin password: ";
    std::cin >> password;

    if (password == "pokemon") {
        showAdminDashboard();
    } else {
        std::cout << "Invalid password. Press any key to continue...";
        _getch();
    }
}

// --- Patient Dashboard & Actions ---
void Menu::showPatientDashboard() {
     while (true) {
        std::vector<std::string> options = {"Book New Appointment", "View My Appointments", "Logout"};
        std::string title = "Welcome, " + loggedInUser + "!";
        int choice = getMenuChoice(options, title);

        switch (choice) {
            case 0: bookNewAppointment(); break;
            case 1: viewMyAppointments(); break;
            case 2: loggedInUser = ""; return; // Logout
        }
    }
}

void Menu::bookNewAppointment() {
    system("cls");
    std::cout << "--- Step 1: Your Details ---" << std::endl;
    std::string pName, pProblem;
    int pAge;
    clearInputBuffer();
    std::cout << "Your Full Name: ";
    std::getline(std::cin, pName);
    std::cout << "Your Age: ";
    std::cin >> pAge;
    clearInputBuffer();
    std::cout << "Primary Symptom/Problem: ";
    std::getline(std::cin, pProblem);

    // Step 2: Find Doctor
    std::string specialty;
    if (pProblem.find("heart") != std::string::npos || pProblem.find("chest") != std::string::npos) specialty = "Cardiology";
    else if (pProblem.find("skin") != std::string::npos) specialty = "Dermatology";
    else specialty = "General Practice";

    auto doctors = doctorDb.findDoctorsBySpeciality(specialty);
    if (doctors.empty()) {
        std::cout << "No doctors found for that specialty. Press any key...";
        _getch();
        return;
    }

    std::cout << "\n--- Step 2: Select a Doctor ---" << std::endl;
    std::cout << "We suggest a " << specialty << " specialist." << std::endl;
    for(const auto& doc : doctors) {
        std::cout << "ID: " << doc.getId() << ", Name: " << doc.getName() << std::endl;
    }
    std::cout << "Enter Doctor ID: ";
    int docId;
    std::cin >> docId;
    std::string docName;
    bool foundDoc = false;
    for(const auto& doc : doctors) {
        if(doc.getId() == docId) {
            docName = doc.getName();
            foundDoc = true;
            break;
        }
    }
    if(!foundDoc){
        std::cout << "Invalid Doctor ID. Press any key...";
        _getch();
        return;
    }

    // Step 3: Check Availability
    std::cout << "\n--- Step 3: Choose Date ---" << std::endl;
    std::string date;
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::cin >> date;

    const int MAX_APP_PER_DAY = 5;
    if (appointmentDb.getAppointmentCountForDoctor(docName, date) >= MAX_APP_PER_DAY) {
        std::cout << "Doctor is fully booked on this date. Press any key...";
        _getch();
        return;
    }

    // Step 4: Confirmation
    std::cout << "\n--- Step 4: Confirmation ---" << std::endl;
    std::cout << "Patient: " << pName << std::endl;
    std::cout << "Doctor: " << docName << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Confirm appointment? (y/n): ";
    char confirm;
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        patientDb.addPatient(pName, pAge, pProblem, loggedInUser);
        appointmentDb.addAppointment(pName, docName, date);
        std::cout << "Appointment confirmed! Press any key...";
    } else {
        std::cout << "Appointment cancelled. Press any key...";
    }
    _getch();
}

void Menu::viewMyAppointments() {
    // This is a placeholder. A real implementation would read appointments for the loggedInUser.
    system("cls");
    std::cout << "--- My Appointments ---" << std::endl;
    std::cout << "(Feature coming soon...)" << std::endl;
    std::cout << "Press any key to return to the dashboard...";
    _getch();
}

// --- Admin Dashboard & Actions ---
void Menu::showAdminDashboard() {
     while (true) {
        std::vector<std::string> options = {"Manage Doctors", "Logout"};
        int choice = getMenuChoice(options, "Admin Dashboard");

        switch (choice) {
            case 0: manageDoctors(); break;
            case 1: return; // Logout
        }
    }
}

void Menu::manageDoctors() {
    system("cls");
    std::cout << "--- Manage Doctors ---" << std::endl;
    const auto& doctors = doctorDb.getAllDoctors();
    for(const auto& doc : doctors) {
        std::cout << "ID: " << doc.getId() << ", Name: " << doc.getName() << ", Spec: " << doc.getSpecialization() << std::endl;
    }
    std::cout << "\n(Admin doctor management functions would go here)" << std::endl;
    std::cout << "Press any key to return to the dashboard...";
    _getch();
}