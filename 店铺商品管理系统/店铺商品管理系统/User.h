#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;

public:
    User(std::string name, std::string pwd);
    std::string getPassword() const {
        return password;
    }
    bool authenticate(std::string pwd) const;
};

#endif  // USER_H
