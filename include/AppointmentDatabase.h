#ifndef APPOINTMENT_DATABASE_H
#define APPOINTMENT_DATABASE_H

#include <vector>
#include "Appointment.h"
#include "FileService.h"

class AppointmentDatabase {
private:
    std::vector<Appointment> appointments;
    std::string filePath;
    int nextId = 1;
    void save();

public:
    AppointmentDatabase(std::string filePath);
    void addAppointment(const std::string& pName, const std::string& dName, const std::string& date);
    int getAppointmentCountForDoctor(const std::string& doctorName, const std::string& date);
    // Other admin methods...
};

#endif // APPOINTMENT_DATABASE_H
