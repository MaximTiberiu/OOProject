#include "../include/Interface.h"
#include "../rlutil/rlutil.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <regex>


#define waitkey rlutil::anykey("Press any key to continue...\n")

// MAIN METHOD

/// Function that opens the app.
void Interface::startApp() {
    // loading data
    loadUsersData(userFile, users);
    loadAdminsData(adminFile, admins);

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Reddit++\n";
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Please select an option from the menu below: \n";
    std::cout << "1. Login\n";
    std::cout << "2. Create a New Account\n";
    std::cout << "3. Quit\n\n";

    std::cout << "Please select your choice: ";
    rlutil::setColor(rlutil::CYAN);
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
            rlutil::setColor(rlutil::RED);
            waitkey;
            return;
        }
        default: {
            rlutil::setColor(rlutil::RED);
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
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);

    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Signup\n";
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Please select an option from the menu below: \n";
    std::cout << "1. Signup as User\n";
    std::cout << "2. Signup as Admin\n";
    std::cout << "3. Return to Main Menu\n";
    std::cout << "4. Quit\n\n";

    std::cout << "Please select your choice: ";
    rlutil::setColor(rlutil::CYAN);
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
            rlutil::setColor(rlutil::RED);
            waitkey;
            return;
        }
        default: {
            rlutil::setColor(rlutil::RED);
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
    std::fstream out;
    out.open(fileName, std::ios::app);

    std::string username, pass1, pass2, email;
    bool cond;
    std::cin.ignore(100, '\n');

    cond = false;
    while(!cond) {
        rlutil::setColor(rlutil::YELLOW);
        std::cout << "Username: ";
        rlutil::setColor(rlutil::CYAN);
        std::getline(std::cin, username);

        if(!checkUsername(username)) {
            rlutil::setColor(rlutil::RED);
            std::cout << "White-spaces are not allowed in username! Please try again!\n";
        }
        else if(!checkDuplicateUsername(username)) {
            rlutil::setColor(rlutil::RED);
            std::cout << "Username "<< username <<" is already taken! Please try again!\n";
        }
        else cond = true;
    }

    cond = false;
    while(!cond) {
        rlutil::setColor(rlutil::YELLOW);
        std::cout << "Email: ";
        rlutil::setColor(rlutil::CYAN);
        std::getline(std::cin, email);

        if(!checkEmail(email)) {
            rlutil::setColor(rlutil::RED);
            std::cout << "Invalid email address. Please try again!\n";
        }
        else if(!checkDuplicateEmail(email)) {
            rlutil::setColor(rlutil::RED);
            std::cout << "Email " << email <<" is already taken. Please try again!\n";
        }
        else cond = true;
    }

    rlutil::setColor(rlutil::YELLOW);
        std::cout << "Password: ";
    rlutil::setColor(rlutil::CYAN);
        std::getline(std::cin, pass1);
    rlutil::setColor(rlutil::YELLOW);
        std::cout << "Confirm Password: ";
    rlutil::setColor(rlutil::CYAN);
        std::getline(std::cin, pass2);
    cond = checkPass(pass1, pass2);

    while(!cond)
    {
        rlutil::setColor(rlutil::RED);
        std::cout << "Those passwords didn't match. Please try again!\n";

        rlutil::setColor(rlutil::YELLOW);
            std::cout << "Password: ";
        rlutil::setColor(rlutil::CYAN);
            std::getline(std::cin, pass1);
        rlutil::setColor(rlutil::YELLOW);
            std::cout << "Confirm Password: ";
        rlutil::setColor(rlutil::CYAN);
            std::getline(std::cin, pass2);
        cond = checkPass(pass1, pass2);
    }

    User temp(username, encryptPass(pass1, key), email);
    users.push_back(temp);

    rlutil::setColor(rlutil::YELLOW);
    std::cout << "Your account has been successfully created! Please wait...\n";
    std::this_thread::sleep_for(std::chrono::seconds (5));
    out << temp;
    out.close();
    startApp();
}

/**
 * Function that  creates a new admin account in the app.
 *
 * @param[in] fileName std::string,
 * output file that stores admins' data
 */
void Interface::signupAdmin(const std::string& fileName) {
    std::fstream out;
    out.open(fileName, std::ios::app);

    std::string username, pass1, pass2, email;
    bool cond;

    rlutil::setColor(rlutil::YELLOW);
    std::cout << "Username: ";
    rlutil::setColor(rlutil::CYAN);
    std::cin.ignore(100, '\n');
    std::getline(std::cin, username);
    cond = checkUsername(username);

    while(!cond) {
        rlutil::setColor(rlutil::RED);
        std::cout << "White-spaces are not allowed in username! Please try again!\n";

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "Username: ";
        rlutil::setColor(rlutil::CYAN);
        std::getline(std::cin, username);
        cond = checkUsername(username);
    }

    rlutil::setColor(rlutil::YELLOW);
    std::cout << "Email: ";
    rlutil::setColor(rlutil::CYAN);
    std::getline(std::cin, email);
    cond = checkEmail(email);

    while(!cond) {
        rlutil::setColor(rlutil::RED);
        std::cout << "Invalid email address. Please try again!\n";

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "Email: ";
        rlutil::setColor(rlutil::CYAN);
        std::getline(std::cin, email);
        cond = checkEmail(email);
    }

    rlutil::setColor(rlutil::YELLOW);
    std::cout << "Password: ";
    rlutil::setColor(rlutil::CYAN);
    std::getline(std::cin, pass1);
    rlutil::setColor(rlutil::YELLOW);
    std::cout << "Confirm Password: ";
    rlutil::setColor(rlutil::CYAN);
    std::getline(std::cin, pass2);
    cond = checkPass(pass1, pass2);

    while(!cond) {
        rlutil::setColor(rlutil::RED);
        std::cout << "Those passwords didn't match. Please try again!\n";

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "Password: ";
        rlutil::setColor(rlutil::CYAN);
        std::getline(std::cin, pass1);
        rlutil::setColor(rlutil::YELLOW);
        std::cout << "Confirm Password: ";
        rlutil::setColor(rlutil::CYAN);
        std::getline(std::cin, pass2);
        cond = checkPass(pass1, pass2);
    }
    Admin temp(username, encryptPass(pass1, key), email);
    admins.push_back(temp);

    rlutil::setColor(rlutil::YELLOW);
    std::cout << "Your account has been successfully created! Please wait...\n";
    std::this_thread::sleep_for(std::chrono::seconds (5));

    out << temp;
    out.close();
    startApp();
}

// LOGIN METHODS

/// Function that shows the login form.
void Interface::login() {
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);

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
    rlutil::setColor(rlutil::CYAN);
    std::cin >> option;

    switch(option) {
        case 1: {
            User temp;
            std::cout << temp.getUsername() << "\n";
            std::string user, pass;
            std::cout << "Username: ";
            std::cin.ignore(100, '\n');

            std::getline(std::cin, user);

            std::cout << "Password: ";
            std::getline(std::cin, pass);

            if(loginUser(user, pass, userFile, temp)){
              rlutil::setColor(rlutil::GREEN);
              std::cout << "Loading...\n";

              for(int i = 0 ; i < 9 ; i++) {
                  std::cout << '-';
                  std::this_thread::sleep_for(std::chrono::milliseconds(30));
              }
              panel(temp);
            }
            else {
                rlutil::setColor(rlutil::RED);
                std::cout << "Login unsuccessful. Please try again...\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                login();
            }
            return;
        }
        case 2: {
            Admin temp;
            std::string user, pass;
            std::cout << "Username: ";
            std::cin.ignore(100, '\n');

            std::getline(std::cin, user);

            std::cout << "Password: ";
            std::getline(std::cin, pass);

            if(loginAdmin(user, pass, adminFile, temp)){
                rlutil::setColor(rlutil::GREEN);
                std::cout << "Loading...\n";

                for(int i = 0 ; i < 9 ; i++) {
                    std::cout << '-';
                    std::this_thread::sleep_for(std::chrono::milliseconds(30));
                }
                std::cout << "\n";
                panel(temp);
            }
            else {
                rlutil::setColor(rlutil::RED);
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
            rlutil::setColor(rlutil::RED);
            //waitkey; - comm pentru Github Action
            return;
        }
        default: {
            rlutil::setColor(rlutil::RED);
            std::cout << "Incorrect option!\n";
            login();
            return;
        }
    }
}

/**
 * Function that validates an user by its username/email and password
 *
 * @param[in] userOrEmail std::string,
 * field that contains user's username or email
 *
 * @param[in] pass std::string,
 * filed that contains user's password
 *
 * @param[in] fileName std::string,
 * input file that stores all users' authetication data
 *
 * @param[out] user User,
 * object that stores all data about it in case of validation
 *
 * @return true, if the authentication was succesdful, else false
 */
bool Interface::loginUser(const std::string& userOrEmail, const std::string& pass, const std::string& fileName, User& user) {
    for(auto &us : users)
        if((userOrEmail.compare(us.getUsername()) == 0 || userOrEmail.compare(us.getEmail()) == 0) && encryptPass(pass, key).compare(us.getPassword()) == 0){
            user = us;
            return true;
        }
    return false;
}


/**
 * Function that validates an admin by its username/email and password
 *
 * @param[in] userOrEmail std::string,
 * field that contains admin's username or email
 *
 * @param[in] pass std::string,
 * filed that contains admin's password
 *
 * @param[in] fileName std::string,
 * input file that stores all admins' authetication data
 *
 * @param[out] admin Admin,
 * object that stores all data about it in case of validation
 *
 * @return true, if the authentication was succesdful, else false
 */
bool Interface::loginAdmin(const std::string& userOrEmail, const std::string& pass, const std::string& fileName, Admin& admin) {
    for(auto &ad : admins)
        if((userOrEmail.compare(ad.getUsername()) == 0 || userOrEmail.compare(ad.getEmail()) == 0) && encryptPass(pass, key).compare(ad.getPassword()) == 0){
            admin = ad;
            return true;
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
        if(username.compare(us.getUsername()) == 0) return false;

    for(auto &ad : admins)
        if(username.compare(ad.getUsername()) == 0) return false;
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
        if(email.compare(us.getEmail()) == 0) return false;

    for(auto &ad : admins)
        if(email.compare(ad.getEmail()) == 0) return false;
    return true;
}

// LOADING DATA METHODS
/**
 * Function that loads users' authentication datas in app
 *
 * @param[in] fileName std::string,
 * input file that stores the datas
 *
 * @param[out] users std::vector<User>,
 * vector that stores all users' datas existing in fileName
 */
void Interface::loadUsersData(const std::string& fileName, std::vector<User>& users) {
    std::ifstream fin(fileName);
    std::string username, password, email;

    while(!fin.eof()) {
        fin >> username >> password >> email;
        User temp(username, password, email);
        users.push_back(temp);
    }
    fin.close();

    for(auto & user : users)
        std::cout << user.getUsername() << " ";
}

/**
 * Function that loads admins' authentication datas in app
 *
 * @param[in] fileName std::string,
 * input file that stores the datas
 *
 * @param[out] users std::vector<Admin>,
 * vector that stores all admins' datas existing in fileName
 */
void Interface::loadAdminsData(const std::string& fileName, std::vector<Admin>& admins) {
    std::ifstream fin(fileName);

    std::string username, password, email;

    while(!fin.eof()) {
        fin >> username >> password >> email;
        Admin temp(username, password, email);
        admins.push_back(temp);
    }

    fin.close();
}

// MAIN PANEL METHODS

/// Function that shows the main panel for user
void Interface::panel(User& user) {
    rlutil::cls();
    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Welcome, " << user.getUsername() <<"!\n";
    std::cout << "-------------------------------------------------\n\n";
    waitkey;
    return;

}

/// Function that shows the main panel for admin
void Interface::panel(Admin& admin) {
    rlutil::cls();
    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Welcome, " << admin.getUsername() <<"!\n";
    std::cout << "-------------------------------------------------\n\n";
    waitkey;
    return;
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