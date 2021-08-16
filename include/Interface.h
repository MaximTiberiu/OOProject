#pragma once

#include "Admin.h"
#include "User.h"
#include "Channel.h"
#include "LoginWrapper.h"
#include <fstream>
#include <vector>
#include <memory>

class Interface { // Singleton
private:
    static Interface* instance;
    Interface() = default;

    std::vector<std::unique_ptr<Participant>> admins;
    std::vector<std::unique_ptr<Participant>> users;
    std::vector<Channel*> channels;

    unsigned short option;

    const char* key = "password";
    const std::string adminFile = "../appFiles/adminsLogin.txt";
    const std::string userFile = "../appFiles/usersLogin.txt";
    const std::string channelFile = "../appFiles/channels.txt";

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
    static void loadChannelsData(const std::string&, std::vector<Channel*>&);

    // main panel method
    static void panel(User&);
    static void panel(Admin&);

    // security methods
    static std::string encryptPass(const std::string&, const char*);

public:
    static Interface* getInstance();
    ~Interface() = default;

    void startApp();
};
