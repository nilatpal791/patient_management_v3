#ifndef FILE_SERVICE_H
#define FILE_SERVICE_H

#include <vector>
#include <string>
#include "User.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"

class FileService {
public:
    static std::vector<User> readUsers(const std::string& filePath);
    static void writeUsers(const std::string& filePath, const std::vector<User>& users);

    static std::vector<Doctor> readDoctors(const std::string& filePath);
    static void writeDoctors(const std::string& filePath, const std::vector<Doctor>& doctors);

    static std::vector<Patient> readPatients(const std::string& filePath);
    static void writePatients(const std::string& filePath, const std::vector<Patient>& patients);

    static std::vector<Appointment> readAppointments(const std::string& filePath);
    static void writeAppointments(const std::string& filePath, const std::vector<Appointment>& appointments);
};

#endif // FILE_SERVICE_H
