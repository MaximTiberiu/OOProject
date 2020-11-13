#pragma once

#include <list>
#include "Admin.h"
#include "User.h"
#include <fstream>

class Interface {
private:
    std::list<Admin> admins;
    std::list<User> users;

    unsigned short option;

    const std::string adminFile = "../appFiles/admins.txt";
    const std::string userFile = "../appFiles/users.txt";

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
    //void startAppTEST(std::ifstream&);

    static void openFile(std::ifstream&, const std::string&);
    static void openFile(std::ofstream&, const std::string&);

    static void closeFile(std::ifstream&);
    static void closeFile(std::ofstream&);
};
