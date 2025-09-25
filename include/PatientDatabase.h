#ifndef PATIENT_DATABASE_H
#define PATIENT_DATABASE_H

#include <vector>
#include "Patient.h"
#include "FileService.h"

class PatientDatabase {
private:
    std::vector<Patient> patients;
    std::string filePath;
    int nextId = 1;
    void save();

public:
    PatientDatabase(std::string filePath);
    void addPatient(const std::string& name, int age, const std::string& problem, const std::string& ownerUsername);
    // Other admin methods...
};

#endif // PATIENT_DATABASE_H
