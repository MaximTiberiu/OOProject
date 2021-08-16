#pragma once

// include
#include <string>
#include <vector>
#include <memory>
#include "./Channel.h"

enum Grade {
    firstTimer,
    regularJoe,
    activist,
    addict,
    master
};

class Participant {
protected:
    std::string username;
    std::string password;
    std::string email;
    Grade grade;
    std::string userDataFile;
    std::vector<Channel*> channels;

    void setUserDataFile();

public:

    Participant();
    Participant(const std::string&, const std::string&, const std::string&);
    Participant(const std::string&, const std::string&, const std::string&, const std::vector<Channel*>&);
    Participant(const Participant&);
    virtual ~Participant();

    // getters
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getEmail() const;
    Grade getGrade() const;
    std::string getUserDataFile() const;

    // setters
    void setUsername(const std::string&);
    void setPassword(const std::string&);
    void setEmail(const std::string&);
    void setGrade(Grade&);
    void setChannel(const std::vector<Channel*>&);
    void getChannels();

    virtual std::unique_ptr<Participant> clone() = 0;
};