#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include <vector>
#include "User.h"
#include "FileService.h"

class AuthService {
private:
    std::vector<User> users;
    std::string filePath;
    void save();

public:
    AuthService(std::string filePath);
    bool signUp(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
};

#endif // AUTH_SERVICE_H
