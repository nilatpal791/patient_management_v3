#include "Patient.h"

Patient::Patient(int id, std::string name, int age, std::string problem, std::string ownerUsername)
    : id(id), name(name), age(age), problem(problem), ownerUsername(ownerUsername) {}

int Patient::getId() const { return id; }
std::string Patient::getName() const { return name; }
std::string Patient::getOwnerUsername() const { return ownerUsername; }
int Patient::getAge() const { return age; }
std::string Patient::getProblem() const { return problem; }
