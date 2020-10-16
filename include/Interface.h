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
    Admin admin;
    std::list<User> users;
    unsigned short opt;

    const std::string adminFile = "../appFiles/admins.txt";
    const std::string userFile = "../appFiles/users.txt";

public:
    void startApp();
    void login();
    void signup();
    void signupAdmin(const std::string);
    void signupUser(const std::string);
};
