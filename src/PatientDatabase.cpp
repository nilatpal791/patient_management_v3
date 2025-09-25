#include "PatientDatabase.h"

PatientDatabase::PatientDatabase(std::string filePath) : filePath(filePath) {
    patients = FileService::readPatients(filePath);
    if (!patients.empty()) {
        nextId = patients.back().getId() + 1;
    }
}

void PatientDatabase::save() {
    FileService::writePatients(filePath, patients);
}

void PatientDatabase::addPatient(const std::string& name, int age, const std::string& problem, const std::string& ownerUsername) {
    patients.emplace_back(nextId++, name, age, problem, ownerUsername);
    save();
}
