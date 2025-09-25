#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string username, std::string password);
    std::string getUsername() const;
    bool checkPassword(const std::string& pass) const;
};

#endif // USER_H
