#include "../include/Interface.h"
#include "../rlutil/rlutil.h"
#include <iostream>
#include <chrono>
#include <memory>
#include <thread>
#include <regex>

#ifdef GH_ACTIONS
    #define waitkey (void)
#else
    #define waitkey rlutil::anykey("Press any key to continue...\n")
#endif

#define setRed rlutil::setColor(rlutil::RED)
#define setYellow rlutil::setColor(rlutil::YELLOW)
#define setCyan rlutil::setColor(rlutil::CYAN)
#define setGreen rlutil::setColor(rlutil::GREEN)
#define clear rlutil::cls()

// MAIN METHOD

/// Function that opens the app.
void Interface::startApp() {
    // loading login data
    loadUsersData(userFile, users);
    loadAdminsData(adminFile, admins);

    clear;
    setYellow;
    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Reddit++\n";
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Please select an option from the menu below: \n";
    std::cout << "1. Login\n";
    std::cout << "2. Create a New Account\n";
    std::cout << "3. Quit\n\n";

    std::cout << "Please select your choice: ";
    setCyan;
    std::cin >> option;

    switch(option) {
        case 1: {
            login();
            return;
        }
        case 2: {
            signup();
            return;
        }
        case 3: {
            setRed;
            waitkey;
            return;
        }
        default: {
            setRed;
            std::cout << "Incorrect option!\n";

            std::this_thread::sleep_for(std::chrono::seconds(2));
            startApp();
            return;
        }
    }
}

// SIGNUP METHODS

/// Function that shows the signup form.
void Interface::signup() {
    clear;
    setYellow;

    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Signup\n";
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Please select an option from the menu below: \n";
    std::cout << "1. Signup as User\n";
    std::cout << "2. Signup as Admin\n";
    std::cout << "3. Return to Main Menu\n";
    std::cout << "4. Quit\n\n";

    std::cout << "Please select your choice: ";
    setCyan;
    std::cin >> option;

    switch(option) {
        case 1: {
            signupUser(userFile);
            return;
        }
        case 2: {
            signupAdmin(adminFile);
            return;
        }
        case 3: {
            startApp();
            return;
        }
        case 4: {
            setRed;
            waitkey;
            return;
        }
        default: {
            setRed;
            std::cout << "Incorrect option!\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            signup();
            return;
        }
    }
}

/**
 * Function that  creates a new user account in the app.
 *
 * @param[in] fileName std::string,
 * output file that stores users' data
 */
void Interface::signupUser(const std::string& fileName) {
    std::fstream outLogin;
    outLogin.open(fileName, std::ios::app);

    std::string username, pass1, pass2, email;
    bool cond;
    std::cin.ignore(100, '\n');

    cond = false;
    while(!cond) {
        setYellow;
        std::cout << "Username: ";
        setCyan;
        std::getline(std::cin, username);

        if(!checkUsername(username)) {
            setRed;
            std::cout << "White-spaces are not allowed in username! Please try again!\n";
        }
        else if(!checkDuplicateUsername(username)) {
            setRed;
            std::cout << "Username "<< username <<" is already taken! Please try again!\n";
        }
        else cond = true;
    }

    cond = false;
    while(!cond) {
        setYellow;
        std::cout << "Email: ";
        setCyan;
        std::getline(std::cin, email);

        if(!checkEmail(email)) {
            setRed;
            std::cout << "Invalid email address. Please try again!\n";
        }
        else if(!checkDuplicateEmail(email)) {
            setRed;
            std::cout << "Email " << email <<" is already taken. Please try again!\n";
        }
        else cond = true;
    }

    setYellow;
        std::cout << "Password: ";
    setCyan;
        std::getline(std::cin, pass1);
    setYellow;
        std::cout << "Confirm Password: ";
    setCyan;
        std::getline(std::cin, pass2);
    cond = checkPass(pass1, pass2);

    while(!cond)
    {
        setRed;
        std::cout << "Those passwords didn't match. Please try again!\n";

        setYellow;
            std::cout << "Password: ";
        setCyan;
            std::getline(std::cin, pass1);
        setYellow;
            std::cout << "Confirm Password: ";
        setCyan;
            std::getline(std::cin, pass2);
        cond = checkPass(pass1, pass2);
    }

    auto temp = std::make_unique<User>(username, encryptPass(pass1, key), email);
    LoginWrapper l(*temp);
    outLogin << l;

    std::fstream outFile;
    outFile.open(temp->getUserDataFile(), std::ios::out);
    outFile << *temp;
    outFile.close();
    users.push_back(std::move(temp));

    setYellow;
    std::cout << "Your account has been successfully created! Please wait...\n";
    std::this_thread::sleep_for(std::chrono::seconds (5));

    outLogin.close();
    startApp();
}

/**
 * Function that  creates a new admin account in the app.
 *
 * @param[in] fileName std::string,
 * output file that stores admins' data
 */
void Interface::signupAdmin(const std::string& fileName) {
    std::fstream outLogin;
    outLogin.open(fileName, std::ios::app);

    std::string username, pass1, pass2, email;
    bool cond;
    std::cin.ignore(100, '\n');

    cond = false;
    while(!cond) {
        setYellow;
        std::cout << "Username: ";
        setCyan;
        std::getline(std::cin, username);

        if(!checkUsername(username)) {
            setRed;
            std::cout << "White-spaces are not allowed in username! Please try again!\n";
        }
        else if(!checkDuplicateUsername(username)) {
            setRed;
            std::cout << "Username "<< username <<" is already taken! Please try again!\n";
        }
        else cond = true;
    }

    cond = false;
    while(!cond) {
        setYellow;
        std::cout << "Email: ";
        setCyan;
        std::getline(std::cin, email);

        if(!checkEmail(email)) {
            setRed;
            std::cout << "Invalid email address. Please try again!\n";
        }
        else if(!checkDuplicateEmail(email)) {
            setRed;
            std::cout << "Email " << email <<" is already taken. Please try again!\n";
        }
        else cond = true;
    }

    setYellow;
    std::cout << "Password: ";
    setCyan;
    std::getline(std::cin, pass1);
    setYellow;
    std::cout << "Confirm Password: ";
    setCyan;
    std::getline(std::cin, pass2);
    cond = checkPass(pass1, pass2);

    while(!cond) {
        setRed;
        std::cout << "Those passwords didn't match. Please try again!\n";

        setYellow;
        std::cout << "Password: ";
        setCyan;
        std::getline(std::cin, pass1);
        setYellow;
        std::cout << "Confirm Password: ";
        setCyan;
        std::getline(std::cin, pass2);
        cond = checkPass(pass1, pass2);
    }

    auto temp = std::make_unique<Admin>(username, encryptPass(pass1, key), email);
    LoginWrapper l(*temp);
    outLogin << l;

    std::fstream outFile;
    outFile.open(temp->getUserDataFile(), std::ios::out);
    //outFile << *temp;
    outFile.close();
    admins.push_back(std::move(temp));

    setYellow;
    std::cout << "Your account has been successfully created! Please wait...\n";
    std::this_thread::sleep_for(std::chrono::seconds (5));

    outLogin.close();
    startApp();
}

// LOGIN METHODS

/// Function that shows the login form.
void Interface::login() {
    clear;
    setYellow;

    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Login\n";
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Please select an option from the menu below: \n";
    std::cout << "1. Login as User\n";
    std::cout << "2. Login as Admin\n";
    std::cout << "3. Login as Guest\n";
    std::cout << "4. Return to Main Menu\n";
    std::cout << "5. Quit\n\n";

    std::cout << "Please select your choice: ";
    setCyan;
    std::cin >> option;

    switch(option) {
        case 1: {
            User temp;
            std::cout << temp.getUsername() << "\n";
            std::string user, pass;
            std::cout << "Username/Email: ";
            std::cin.ignore(100, '\n');

            std::getline(std::cin, user);

            std::cout << "Password: ";
            std::getline(std::cin, pass);

            if(loginUser(user, pass, temp, users)){
              setGreen;
              std::cout << "Loading...\n";

              for(int i = 0 ; i < 9 ; i++) {
                  std::cout << '-';
                  std::this_thread::sleep_for(std::chrono::milliseconds(30));
              }
              temp.userPanel();
            }
            else {
                setRed;
                std::cout << "Login unsuccessful. Please try again...\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                login();
            }
            return;
        }
        case 2: {
            Admin temp;
            std::string user, pass;
            std::cout << "Username/Email: ";
            std::cin.ignore(100, '\n');

            std::getline(std::cin, user);

            std::cout << "Password: ";
            std::getline(std::cin, pass);

            if(loginUser(user, pass, temp, admins)){
                setGreen;
                std::cout << "Loading...\n";

                for(int i = 0 ; i < 9 ; i++) {
                    std::cout << '-';
                    std::this_thread::sleep_for(std::chrono::milliseconds(30));
                }
                std::cout << "\n";
                panel(temp);
            }
            else {
                setRed;
                std::cout << "Login unsuccessful. Please try again...\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                login();
            }
            return;
        }
        case 3: {
            // panel("GUEST");
            return;
        }
        case 4: {
            startApp();
            return;
        }
        case 5: {
            setRed;
            waitkey;
            return;
        }
        default: {
            setRed;
            std::cout << "Incorrect option!\n";
            login();
            return;
        }
    }
}

/**
 * Function that validates a participant by its username/email and password
 *
 * @param[in] userOrEmail std::string,
 * field that contains admin's username or email
 *
 * @param[in] pass std::string,
 * filed that contains admin's password
 *
 * @param[out] participant Participant,
 * object that stores all data about it in case of validation
 *
 * @param[in] participants std::vector<std::unique_ptr<Participant>>
 * vector that stores all users/admins data
 *
 * @return true, if the authentication was succesdful, else false
 */
bool Interface::loginUser(const std::string &userOrEmail, const std::string &pass, Participant& participant, const std::vector<std::unique_ptr<Participant>>& participants) {
    for(auto &part : participants) {
        if ((userOrEmail.compare(part->getUsername()) == 0 || userOrEmail.compare(part->getEmail()) == 0) && encryptPass(pass, key).compare(part->getPassword()) == 0) {
            participant = *part;
            return true;
        }
    }
    return false;
}

// VALIDATION METHODS

/**
 * Function that checks if the two passwords are the same
 *
 * @param[in] pass1 std::string,
 * first password
 *
 * @param[in] pass2 std::string,
 * second password
 *
 * @return true, if the passwords are equals, else false
 */
bool Interface::checkPass(const std::string& pass1, const std::string& pass2) {
    return pass1 == pass2;
}

/**
 * Function that checks if the username contains any spaces
 *
 * @param[in] username std::string,
 * username field
 *
 * @return true, if username is valid, else false
 */
bool Interface::checkUsername(const std::string& username) {
    return username.find(' ') == std::string::npos;
}

/**
 * Function that checks if the email contains 'at' char
 *
 * @param[in] email std::string,
 * email field
 *
 * @return true if email is valid, else false
 */
bool Interface::checkEmail(const std::string& email) {
    const std::regex pattern("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)");
    return std::regex_match(email, pattern);
}

/**
 * Function that checks if the valid username is already used by another user/admin
 *
 * @param[in] username std::string,
 * username field
 *
 * @return true if username isn't used, else false
 */
bool Interface::checkDuplicateUsername(const std::string& username) {
    for(auto &us : users)
        if(username.compare(us->getUsername()) == 0) return false;

    for(auto &ad : admins)
        if(username.compare(ad->getUsername()) == 0) return false;
    return true;
}


/**
 * Function that checks if the valid email is already used by another user/admin
 *
 * @param[in] email std::string,
 * email field
 *
 * @return true if email isn't used, else false
 */
bool Interface::checkDuplicateEmail(const std::string& email) {
    for(auto &us : users)
        if(email.compare(us->getEmail()) == 0) return false;

    for(auto &ad : admins)
        if(email.compare(ad->getEmail()) == 0) return false;
    return true;
}

// LOADING DATA METHODS

/**
 * Function that loads users' authentication data in app
 *
 * @param[in] fileName std::string,
 * input file that stores the data
 *
 * @param[out] users std::vector<std::unique_ptr<User>>,
 * vector that stores all users' data existing in fileName
 */
void Interface::loadUsersData(const std::string& fileName, std::vector<std::unique_ptr<Participant>>& users) {
    try {
        std::ifstream fin(fileName);
        fin.exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit);
        std::string username, password, email;

        while(!fin.eof()) {
            fin >> username >> password >> email;
            auto temp = std::make_unique<User>(username, password, email);
            users.push_back(std::move(temp));
        }
        fin.close();
    }
    catch (std::exception const& e) {
        setRed;
        std::cout << "There was an error: " << e.what() << "\n";
    }
}

/**
 * Function that loads admins' authentication data in app
 *
 * @param[in] fileName std::string,
 * input file that stores the data
 *
 * @param[out] admins std::vector<std::unique_ptr<Admin>>,
 * vector that stores all admins' data existing in fileName
 */
void Interface::loadAdminsData(const std::string& fileName, std::vector<std::unique_ptr<Participant>>& admins) {
    try {
        std::ifstream fin(fileName);
        fin.exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit);
        std::string username, password, email;

        while(!fin.eof()) {
            fin >> username >> password >> email;
            auto temp = std::make_unique<Admin>(username, password, email);
            admins.push_back(std::move(temp));
        }

        fin.close();
    }
    catch (std::exception const& e) {
        setRed;
        std::cout << "There was an error: " << e.what() << "\n";
    }
}


// MAIN PANEL METHODS

/// Function that shows the main panel for user
void Interface::panel(User& user) {
    clear;
    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Welcome, " << user.getUsername() <<"!\n";
    std::cout << "-------------------------------------------------\n\n";
    waitkey;
}

/// Function that shows the main panel for admin
void Interface::panel(Admin& admin) {
    clear;
    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Welcome, " << admin.getUsername() <<"!\n";
    std::cout << "-------------------------------------------------\n\n";
    waitkey;
}

// SECURITY METHODS

/**
 * Function that encrypt a given password
 *
 * @param[in] password std::string,
 * password field
 *
 * @param[in] key char*,
 * key used to encrypt the password
 *
 * @return encrypted password, encryptedPass
 */
std::string Interface::encryptPass(const std::string& password, const char* key) {
    std::string encryptedPass = password;
    for(int i = 0 ; i < encryptedPass.size() ; i++) {
        encryptedPass = password[i] ^ key[i % (sizeof(key) / sizeof(char))];
    }
    return encryptedPass;
}