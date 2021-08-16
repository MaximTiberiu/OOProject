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
    std::vector<std::string> channels;
    std::vector<std::string> posts;
    std::vector<std::string> likes;
    std::vector<std::string> dislikes;
    std::vector<std::string> comms;

    void setGrade();

    static void showUserOptions();
    void createChannel();

public:
    User();
    User(const std::string&, const std::string&, const std::string&);
    User(const User&);
    ~User();

    std::unique_ptr<Participant> clone() override;
    friend std::ostream &operator<< (std::ostream&, const User&);
    void userPanel();
};
