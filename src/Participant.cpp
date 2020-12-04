// include
#include "../include/Participant.h"

Participant::Participant() = default;

Participant::Participant(const std::string& username, const std::string& password, const std::string& email) {
    this->username = username;
    this->password = password;
    this->email = email;
    setUserDataFile();
}

Participant::Participant(const Participant& p) {
    username = p.username;
    email = p.email;
    password = p.password;
}

Participant::~Participant() = default;

std::ostream &operator<< (std::ostream &out, const Participant& p) {
    out << "TEST\n";
    return out;
}

std::string Participant::getUsername() const {
    return username;
}

std::string Participant::getPassword() const {
    return password;
}

std::string Participant::getEmail() const {
    return email;
}

Grade Participant::getGrade() const {
    return grade;
}

std::string Participant::getUserDataFile() const {
    return this->userDataFile;
}

void Participant::setUsername(const std::string& newUsername) {
    this->username = newUsername;
}

void Participant::setPassword(const std::string& newPassword) {
    this->password = newPassword;
}

void Participant::setEmail(const std::string& newEmail) {
    this->email = newEmail;
}

void Participant::setGrade(Grade& newGrade) {
    this->grade = newGrade;
}

void Participant::setUserDataFile() {
    std::string path = "../appFiles/users-admins/";
    path += username;
    path += ".txt";

    userDataFile = path;
}