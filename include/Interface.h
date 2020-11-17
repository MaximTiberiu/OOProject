#pragma once

#include <vector>
#include "Admin.h"
#include "User.h"
#include "Guest.h"
#include <fstream>

class Interface {
private:
    std::vector<Admin> admins;
    std::vector<User> users;

    unsigned short option;

    const std::string adminFile = "../appFiles/admins.txt";
    const std::string userFile = "../appFiles/users.txt";

    // signup methods
    void signup();
    void signupUser(const std::string&);
    void signupAdmin(const std::string&);

    // login methods
    void login();
    bool loginUser(const std::string&, const std::string&, const std::string&, User& user);
    bool loginAdmin(const std::string&, const std::string&, const std::string&, Admin& admin);

    // validation methods
    static bool checkPass(const std::string&, const std::string&);
    static bool checkEmail(const std::string&);
    static bool checkUsername(const std::string&);

    // loading data methods
    static void loadUsersData(const std::string&, std::vector<User>&);
    static void loadAdminsData(const std::string&, std::vector<Admin>&);

    // main panel method
    static void panel(User&);
    static void panel(Admin&);
    static void panel(Guest&);

public:
    void startApp();
};
