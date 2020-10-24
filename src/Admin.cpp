// include
#include "../include/Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const std::string& email) {
    this->username = username;
    this->password = password;
    this->email = email;
}

Admin::Admin(const Admin &ad) {
    username = ad.username;
    email = ad.email;
    password = ad.password;
}

Admin::~Admin() = default;

std::ostream& operator<<(std::ostream &out, const Admin& admin) {
    out << admin.username << ";" << admin.password << ";" << admin.email;
}
