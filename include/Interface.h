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
    std::list<Admin>::iterator it = admins.begin();
    std::list<User> users;
    unsigned short opt;

    const std::string adminFile = "../appFiles/admins.txt";
    const std::string userFile = "../appFiles/users.txt";

    static bool checkPass(const std::string&, const std::string&);

public:
    void startApp();
    void login();
    void signup();

    void signupAdmin(const std::string);
    void signupUser(const std::string);

    void loginUser(const std::string user, const std::string pass);
    void loginAdmin(const std::string user, const std::string pass);
};
