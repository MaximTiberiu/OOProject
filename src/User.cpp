// include
#include "../include/User.h"

User::User() = default;

User::User(const std::string& username, const std::string& password, const std::string& email) {
    this->username = username;
    this->password = password;
    this->email = email;

    dateTime = time(nullptr); // current date&time
    ltm = localtime(&dateTime);
}

User::User(const User& us)  : Participant(us) {
    username = us.username;
    email = us.email;
    password = us.password;
    ltm = us.ltm;
    grade = us.grade;
    dateTime = us.dateTime;
}

User::~User() = default;

tm User::get_dateTime() {
    return *ltm;
}

std::string User::getGrade() {
    return grade;
}

void User::set_dateTime(tm *newltm) {
    this->ltm = newltm;
}

void User::setGrade(const std::string& newGrade) {
    this->grade = newGrade;
}

std::ostream &operator<< (std::ostream &out, const User &user) {
    out << user.username << " " << user.password << " " << user.email << "\n";
    return out;
}
