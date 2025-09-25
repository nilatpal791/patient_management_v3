#include "FileService.h"
#include <fstream>
#include <sstream>

// User I/O
std::vector<User> FileService::readUsers(const std::string& filePath) {
    std::vector<User> users;
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string username, password;
        if (std::getline(ss, username, ',') && std::getline(ss, password, ',')) {
            users.emplace_back(username, password);
        }
    }
    return users;
}

void FileService::writeUsers(const std::string& filePath, const std::vector<User>& users) {
    std::ofstream file(filePath);
    for (const auto& user : users) {
        file << user.getUsername() << ',' << "[redacted]" << '\n'; // Avoid writing real passwords
    }
}

// Doctor I/O
std::vector<Doctor> FileService::readDoctors(const std::string& filePath) {
    std::vector<Doctor> doctors;
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, name, spec;
        if (std::getline(ss, id, ',') && std::getline(ss, name, ',') && std::getline(ss, spec, ',')) {
            doctors.emplace_back(std::stoi(id), name, spec);
        }
    }
    return doctors;
}

void FileService::writeDoctors(const std::string& filePath, const std::vector<Doctor>& doctors) {
    std::ofstream file(filePath);
    for (const auto& doctor : doctors) {
        file << doctor.getId() << ',' << doctor.getName() << ',' << doctor.getSpecialization() << '\n';
    }
}

// Patient I/O
std::vector<Patient> FileService::readPatients(const std::string& filePath) {
    std::vector<Patient> patients;
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, name, age, problem, owner;
        if (std::getline(ss, id, ',') && std::getline(ss, name, ',') && std::getline(ss, age, ',') && std::getline(ss, problem, ',') && std::getline(ss, owner, ',')) {
            patients.emplace_back(std::stoi(id), name, std::stoi(age), problem, owner);
        }
    }
    return patients;
}

void FileService::writePatients(const std::string& filePath, const std::vector<Patient>& patients) {
    std::ofstream file(filePath);
    for (const auto& p : patients) {
        file << p.getId() << ',' << p.getName() << ',' << p.getAge() << ',' << p.getProblem() << ',' << p.getOwnerUsername() << '\n';
    }
}

// Appointment I/O
std::vector<Appointment> FileService::readAppointments(const std::string& filePath) {
    std::vector<Appointment> appointments;
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, pName, dName, date;
        if (std::getline(ss, id, ',') && std::getline(ss, pName, ',') && std::getline(ss, dName, ',') && std::getline(ss, date, ',')) {
            appointments.emplace_back(std::stoi(id), pName, dName, date);
        }
    }
    return appointments;
}

void FileService::writeAppointments(const std::string& filePath, const std::vector<Appointment>& appointments) {
    std::ofstream file(filePath);
    for (const auto& app : appointments) {
        file << app.getId() << ',' << app.getPatientName() << ',' << app.getDoctorName() << ',' << app.getAppointmentDate() << '\n';
    }
}
