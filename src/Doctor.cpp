#include "Doctor.h"

Doctor::Doctor(int id, std::string name, std::string specialization)
    : id(id), name(name), specialization(specialization) {}

int Doctor::getId() const { return id; }
std::string Doctor::getName() const { return name; }
std::string Doctor::getSpecialization() const { return specialization; }
void Doctor::setName(std::string name) { this->name = name; }
void Doctor::setSpecialization(std::string specialization) { this->specialization = specialization; }
