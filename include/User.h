#pragma once

// include
#include "Participant.h"
#include <ctime>

class User : public Participant {
private:
    time_t dateTime;
    tm *ltm;

    std::string grade;
public:
    User(const std::string&, const std::string&, const std::string&);
    ~User();

    // getters

    tm get_dateTime();
    std::string getGrade();

    // setters

    void set_dateTime(tm*);
    void setGrade(const std::string&);
};
