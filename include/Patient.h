#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
private:
    int id;
    std::string name;
    int age;
    std::string problem;
    std::string ownerUsername;

public:
    Patient(int id, std::string name, int age, std::string problem, std::string ownerUsername);
    int getId() const;
    std::string getName() const;
    int getAge() const;
    std::string getProblem() const;
    std::string getOwnerUsername() const;
};

#endif // PATIENT_H
