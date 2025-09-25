#include "Appointment.h"

Appointment::Appointment(int id, std::string patientName, std::string doctorName, std::string appointmentDate)
    : id(id), patientName(patientName), doctorName(doctorName), appointmentDate(appointmentDate) {}

int Appointment::getId() const { return id; }
std::string Appointment::getPatientName() const { return patientName; }
std::string Appointment::getDoctorName() const { return doctorName; }
std::string Appointment::getAppointmentDate() const { return appointmentDate; }
