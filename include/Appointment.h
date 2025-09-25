#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class Appointment {
private:
    int id;
    std::string patientName;
    std::string doctorName;
    std::string appointmentDate;

public:
    Appointment(int id, std::string patientName, std::string doctorName, std::string appointmentDate);
    int getId() const;
    std::string getPatientName() const;
    std::string getDoctorName() const;
    std::string getAppointmentDate() const;
};

#endif // APPOINTMENT_H
