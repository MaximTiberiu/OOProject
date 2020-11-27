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
    if(postsNum <= 1) {
        grade = firstTimer;
        return;
    }
    if(postsNum > 1) {
        if(likesNum >= 20) {
            if(commsNum >= 20)
                grade = addict;
            else
                grade = activist;
        } else
            grade = regularJoe;
        return;
    }
    if(postsNum >= 100 && commsNum >= 100 && likesNum >= 100)
        grade = master;
}
