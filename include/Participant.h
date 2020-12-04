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
    //std::vector<std::unique_ptr<Channel>> channels;

    void setUserDataFile();

public:

    Participant();
    Participant(const std::string&, const std::string&, const std::string&);
    Participant(const Participant&);
    virtual ~Participant();
    friend std::ostream &operator<< (std::ostream &, const Participant&);

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

    virtual std::unique_ptr<Participant> clone() = 0;
};