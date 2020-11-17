#pragma once

// include
#include "Participant.h"
#include <ctime>
#include <iostream>

class User : public Participant {
private:

    time_t dateTime{};
    tm *ltm{};

    std::string grade;
    
    void fsetGrade();

public:
    User();
    User(const std::string&, const std::string&, const std::string&);
    User(const User &);
    ~User();

    friend std::ostream &operator<< (std::ostream &, const User &);

    // getters
    tm get_dateTime();
    std::string getGrade();

    // setters
    void set_dateTime(tm*);
    void setGrade(const std::string&);
};
