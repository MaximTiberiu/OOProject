// include
#include "../include/User.h"

User::User() = default;

User::User(const std::string& username, const std::string& password, const std::string& email) {
    this->username = username;
    this->password = password;
    this->email = email;
    fsetGrade();
}

User::User(const std::unique_ptr<User>& us) {
    username = us->username;
    email = us->email;
    password = us->password;
    grade = us->grade;
}

User::~User() = default;

std::ostream &operator<< (std::ostream &out, const std::unique_ptr<User>& user) {
    out << user->username << " " << user->password << " " << user->email << "\n";
    return out;
}

void User::fsetGrade() {
    if(posts.size() <= 1) {
        grade = firstTimer;
        return;
    }
    if(posts.size() > 1) {
        if(likes.size() >= 20) {
            if(comms.size() >= 20)
                grade = addict;
            else
                grade = activist;
        } else
            grade = regularJoe;
        return;
    }
    if(posts.size() >= 100 && comms.size() >= 100 && likes.size() >= 100)
        grade = master;
}
