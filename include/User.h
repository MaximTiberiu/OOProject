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
    std::string userDataFile;
    void setGrade();

public:
    User();
    User(const std::string&, const std::string&, const std::string&);
    User(const User&);
    ~User();
    std::unique_ptr<Participant> clone() override;
};
