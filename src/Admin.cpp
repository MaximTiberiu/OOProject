// include
#include "../include/Admin.h"

Admin::Admin() = default;

Admin::Admin(const std::string& username, const std::string& password, const std::string& email)
                : Participant(username, password, email) {
    this->grade = master;
}

Admin::Admin(const Admin& ad)
                : Participant(ad) {
    grade = ad.grade;
}

Admin::~Admin() = default;

std::ostream& operator<<(std::ostream &out, const Admin& admin) {
    out << admin.username << " " << admin.password << " " << admin.email << "\n";
    return out;
}
