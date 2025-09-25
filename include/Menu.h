#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "AuthService.h"
#include "DoctorDatabase.h"
#include "PatientDatabase.h"
#include "AppointmentDatabase.h"

class Menu {
private:
    AuthService& authService;
    DoctorDatabase& doctorDb;
    PatientDatabase& patientDb;
    AppointmentDatabase& appointmentDb;

    std::string loggedInUser;

    void printInteractiveMenu(const std::vector<std::string>& options, int selected, const std::string& title);
    int getMenuChoice(const std::vector<std::string>& options, const std::string& title);

    // Main Flows
    void handlePatientLogin();
    void handlePatientSignup();
    void handleAdminAccess();

    // Patient-specific flows
    void showPatientDashboard();
    void bookNewAppointment();
    void viewMyAppointments();

    // Admin-specific flows
    void showAdminDashboard();
    void managePatients();
    void manageDoctors();
    void manageAppointments();

public:
    Menu(AuthService& auth, DoctorDatabase& ddb, PatientDatabase& pdb, AppointmentDatabase& adb);
    void run();
};

#endif // MENU_H
