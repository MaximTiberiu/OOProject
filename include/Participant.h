#pragma once

// include
#include <string>
#include <vector>
#include "./Post.h"

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
    std::vector<Post> posts;

public:

    // getters
    std::string getUsername();
    std::string getPassword();
    std::string getEmail();
    Grade getGrade();

    // setters
    void setUsername(const std::string&);
    void setPassword(const std::string&);
    void setEmail(const std::string&);
    void setGrade(Grade&);
};