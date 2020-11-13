#pragma once

// include
#include <string>


class Participant {
protected:
    std::string username;
    std::string password;
    std::string email;

public:

    // getters
    std::string getUsername();
    std::string getPassword();
    std::string getEmail();

    // setters
    void setUsername(const std::string&);
    void setPassword(const std::string&);
    void setEmail(const std::string&);
};