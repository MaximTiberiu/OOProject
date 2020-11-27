// include
#include "../include/User.h"

User::User() = default;

User::User(const std::string& username, const std::string& password, const std::string& email) {
    this->username = username;
    this->password = password;
    this->email = email;
}

User::User(const User& us)  : Participant(us) {
    username = us.username;
    email = us.email;
    password = us.password;
    grade = us.grade;
}

User::~User() = default;

std::ostream &operator<< (std::ostream &out, const User &user) {
    out << user.username << " " << user.password << " " << user.email << "\n";
    return out;
}
