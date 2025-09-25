#include "DoctorDatabase.h"

DoctorDatabase::DoctorDatabase(std::string filePath) : filePath(filePath) {
    doctors = FileService::readDoctors(filePath);
    if (!doctors.empty()) {
        nextId = doctors.back().getId() + 1;
    }
}

void DoctorDatabase::save() {
    FileService::writeDoctors(filePath, doctors);
}

void DoctorDatabase::addDoctor(const std::string& name, const std::string& specialization) {
    doctors.emplace_back(nextId++, name, specialization);
    save();
}

std::vector<Doctor> DoctorDatabase::findDoctorsBySpeciality(const std::string& speciality) {
    std::vector<Doctor> result;
    for (const auto& doctor : doctors) {
        if (doctor.getSpecialization() == speciality) {
            result.push_back(doctor);
        }
    }
    return result;
}

const std::vector<Doctor>& DoctorDatabase::getAllDoctors() const {
    return doctors;
}
