#pragma once

// include
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <list>

#include "Admin.h"
#include "User.h"

class Interface {
private:
    std::list<Admin> admins;
    std::list<Admin>::iterator itA = admins.begin();

    std::list<User> users;
    std::list<User>::iterator itU = users.begin();

    unsigned short opt;

    const std::string adminFile = "../appFiles/admins.txt";
    const std::string userFile = "../appFiles/users.txt";

    // signup methods
    void signup();
    void signupUser(const std::string&);
    void signupAdmin(const std::string&);

    // login methods
    void login();
    void loginUser(const std::string user, const std::string pass);
    void loginAdmin(const std::string user, const std::string pass);

    // validation methods
    static bool checkPass(const std::string&, const std::string&);
    static bool checkEmail(const std::string&);
    static bool checkUsername(const std::string&);

public:
    void startApp();
};
