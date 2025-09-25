#include "AuthService.h"
#include <algorithm>

AuthService::AuthService(std::string filePath) : filePath(filePath) {
    users = FileService::readUsers(filePath);
}

void AuthService::save() {
    FileService::writeUsers(filePath, users);
}

bool AuthService::signUp(const std::string& username, const std::string& password) {
    auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
        return user.getUsername() == username;
    });

    if (it != users.end()) {
        return false; // Username already exists
    }

    users.emplace_back(username, password);
    save();
    return true;
}

bool AuthService::login(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user.getUsername() == username && user.checkPassword(password)) {
            return true;
        }
    }
    return false;
}
