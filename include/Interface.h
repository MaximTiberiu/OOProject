#pragma once

// include
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>

#include "Admin.h"
#include "User.h"

class Interface {
private:
    std::list<Admin> admins;
    std::list<User> users;

    unsigned short opt;

    const std::string adminFile = "../appFiles/admins.txt";
    const std::string userFile = "../appFiles/users.txt";
    static void clear_screen();

    // signup methods
    void signup();
    void signupUser(const std::string&);
    void signupAdmin(const std::string&);

    // login methods
    void login();
    bool loginUser(const std::string&, const std::string&, const std::string&);
    bool loginAdmin(const std::string&, const std::string&, const std::string&);

    // validation methods
    static bool checkPass(const std::string&, const std::string&);
    static bool checkEmail(const std::string&);
    static bool checkUsername(const std::string&);

public:
    void startApp();
};
