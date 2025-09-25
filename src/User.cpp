#include "User.h"

User::User(std::string username, std::string password) : username(username), password(password) {}

std::string User::getUsername() const {
    return username;
}

bool User::checkPassword(const std::string& pass) const {
    return password == pass;
}
