// include
#include "../include/Admin.h"

Admin::Admin() = default;

Admin::Admin(const std::string& username, const std::string& password, const std::string& email) {
    this->username = username;
    this->password = password;
    this->email = email;
    this->grade = master;
}

Admin::Admin(const std::unique_ptr<Admin>& ad) {
    username = ad->username;
    email = ad->email;
    password = ad->password;
    grade = ad->grade;
}

Admin::~Admin() = default;

std::ostream& operator<<(std::ostream &out, const std::unique_ptr<Admin>& admin) {
    out << admin->username << " " << admin->password << " " << admin->email << "\n";
    return out;
}
