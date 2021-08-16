// include
#include "../include/Participant.h"
#include <algorithm>

Participant::Participant() = default;

Participant::Participant(const std::string& username, const std::string& password, const std::string& email) {
    this->username = username;
    this->password = password;
    this->email = email;
    setUserDataFile();
}

Participant::Participant(const std::string& username, const std::string& password, const std::string& email, const std::vector<Channel*>& ch) {
    this->username = username;
    this->password = password;
    this->email = email;
    this->channels = ch;
    setUserDataFile();
}

Participant::Participant(const Participant& p) {
    username = p.username;
    email = p.email;
    password = p.password;
    userDataFile = p.userDataFile;
    grade = p.grade;
    channels = p.channels;
}

Participant::~Participant() = default;

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
    return userDataFile;
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

void Participant::setChannel(const std::vector<Channel*>& ch) {
    std::copy(ch.begin(), ch.end(), std::back_inserter(channels));
}

void Participant::setUserDataFile() {
    std::string path = "../appFiles/users-admins/";
    path += username;
    path += ".txt";

    userDataFile = path;
}

void Participant::getChannels() {
    for(auto & channel : channels)
        std::cout << channel->getName() << " ";
    std::cout << "\n";
}