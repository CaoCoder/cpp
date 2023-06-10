#include "User.h"

User::User(std::string name, std::string pwd)
    : username(name), password(pwd) {}

bool User::authenticate(std::string pwd) const {
    return password == pwd;
}
