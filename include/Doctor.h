#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor {
private:
    int id;
    std::string name;
    std::string specialization;

public:
    Doctor(int id, std::string name, std::string specialization);
    int getId() const;
    std::string getName() const;
    std::string getSpecialization() const;
    void setName(std::string name);
    void setSpecialization(std::string specialization);
};

#endif // DOCTOR_H
