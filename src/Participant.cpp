// include
#include "../include/Participant.h"

std::string Participant::getUsername() {
    return username;
}

std::string Participant::getPassword() {
    return password;
}

std::string Participant::getEmail() {
    return email;
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