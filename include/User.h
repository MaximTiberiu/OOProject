#pragma once

// include
#include "Participant.h"
#include <ctime>
#include <iostream>
#include <chrono>
#include <memory>
#include <vector>

class User : public Participant {
private:

    std::vector<unsigned int> posts;
    std::vector<unsigned int> likes;
    std::vector<unsigned int> comms;

    void fsetGrade();

public:
    User();
    User(const std::string&, const std::string&, const std::string&);
    User(const std::unique_ptr<User>&);
    ~User();

    friend std::ostream &operator<< (std::ostream &, const std::unique_ptr<User>&);

};
