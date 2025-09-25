#ifndef DOCTOR_DATABASE_H
#define DOCTOR_DATABASE_H

#include <vector>
#include "Doctor.h"
#include "FileService.h"

class DoctorDatabase {
private:
    std::vector<Doctor> doctors;
    std::string filePath;
    int nextId = 1;
    void save();

public:
    DoctorDatabase(std::string filePath);
    void addDoctor(const std::string& name, const std::string& specialization);
    std::vector<Doctor> findDoctorsBySpeciality(const std::string& speciality);
    const std::vector<Doctor>& getAllDoctors() const;
    // Other admin methods...
};

#endif // DOCTOR_DATABASE_H
