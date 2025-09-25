#include "AppointmentDatabase.h"

AppointmentDatabase::AppointmentDatabase(std::string filePath) : filePath(filePath) {
    appointments = FileService::readAppointments(filePath);
    if (!appointments.empty()) {
        nextId = appointments.back().getId() + 1;
    }
}

void AppointmentDatabase::save() {
    FileService::writeAppointments(filePath, appointments);
}

void AppointmentDatabase::addAppointment(const std::string& pName, const std::string& dName, const std::string& date) {
    appointments.emplace_back(nextId++, pName, dName, date);
    save();
}

int AppointmentDatabase::getAppointmentCountForDoctor(const std::string& doctorName, const std::string& date) {
    int count = 0;
    for (const auto& app : appointments) {
        if (app.getDoctorName() == doctorName && app.getAppointmentDate() == date) {
            count++;
        }
    }
    return count;
}
