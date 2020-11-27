#pragma once

// include
#include "Participant.h"
#include <ctime>
#include <iostream>
#include <chrono>
#include <memory>

class User : public Participant {
private:
    unsigned int postsNum{};
    unsigned int likesNum{};
    unsigned int commsNum{};

    void fsetGrade();

public:
    User();
    User(const std::string&, const std::string&, const std::string&);
    User(const std::unique_ptr<User>&);
    ~User();

    friend std::ostream &operator<< (std::ostream &, const std::unique_ptr<User>&);


};
