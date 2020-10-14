#pragma once

// include
#include <string>


class Participant{
private:
    std::string username;

public:
    Participant(std::string username);
    ~Participant();
    std::string getUsername();
};