#pragma once

#include "Admin.h"
#include "User.h"
#include "Channel.h"
#include "LoginWrapper.h"
#include <fstream>
#include <vector>
#include <memory>

class Interface {
private:
    std::vector<std::unique_ptr<Participant>> admins;
    std::vector<std::unique_ptr<Participant>> users;
    std::vector<std::unique_ptr<Channel>> channels;

    unsigned short option;

    const char* key = "password";
    const std::string adminFile = "../appFiles/adminsLogin.txt";
    const std::string userFile = "../appFiles/usersLogin.txt";

    // signup methods
    void signup();
    void signupUser(const std::string&);
    void signupAdmin(const std::string&);

    // login methods
    void login();
    bool loginUser(const std::string&, const std::string&, Participant& user, const std::vector<std::unique_ptr<Participant>>&);

    // validation methods
    static bool checkPass(const std::string&, const std::string&);
    static bool checkEmail(const std::string&);
    static bool checkUsername(const std::string&);
    bool checkDuplicateUsername(const std::string&);
    bool checkDuplicateEmail(const std::string&);

    // loading data methods
    static void loadUsersData(const std::string&, std::vector<std::unique_ptr<Participant>>&);
    static void loadAdminsData(const std::string&, std::vector<std::unique_ptr<Participant>>&);

    // main panel method
    static void panel(User&);
    static void panel(Admin&);

    // security methods
    static std::string encryptPass(const std::string&, const char*);

public:
    void startApp();
};
