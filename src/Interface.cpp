#include "../include/Interface.h"
#include "../rlutil/rlutil.h"
#include <iostream>
#include <chrono>
#include <thread>

#define waitkey rlutil::anykey("Press any key to continue...\n")
//#define time 3000


/* Function that opens the app. */
void Interface::startApp() {
    // loading data
    loadUsersData(userFile, users);
    loadAdminsData(adminFile, admins);

    //rlutil::cls();
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
            break;
        }
        case 2: {
            signup();
            break;
        }
        case 3: {
            rlutil::setColor(rlutil::RED);
            waitkey;
            break;
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

/** SIGNUP METHODS **/

/* Function that shows the signup form */
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
            break;
        }
        case 2: {
            signupAdmin(adminFile);
            break;
        }
        case 3: {
            startApp();
            return;
        }
        case 4: {
            rlutil::setColor(rlutil::RED);
            waitkey;
            break;
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

/* Function that  creates a new user account in the app */
void Interface::signupUser(const std::string& fileName) {
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

    User temp(username, pass1, email);
    users.push_back(temp);

    out << temp;
    out.close();
}

/* Function that  creates a new admin account in the app*/
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

    Admin temp(username, pass1, email);
    admins.push_back(temp);

    out << temp;
    out.close();
}

/** LOGIN METHODS **/

/* Function that shows the login form. */
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
            std::string user, pass;
            std::cout << "Username: ";
            std::cin.ignore(100, '\n');

            std::getline(std::cin, user);

            std::cout << "Password: ";
            std::getline(std::cin, pass);

            if (loginUser(user, pass, userFile))
                std::cout << "Bine ai venit, " << user << "!\n";
            break;
        }
        case 2: {
            std::string user, pass;
            std::cout << "Username: ";
            std::cin.ignore(100, '\n');
            std::getline(std::cin, user);

            std::cout << "Password: ";
            std::getline(std::cin, pass);

            if (loginAdmin(user, pass, adminFile))
                std::cout << "Bine ai venit, admin!\n";

            break;
        }
        case 3: {
            // login->
            return;
        }
        case 4: {
            startApp();
            return;
        }
        case 5: {
            rlutil::setColor(rlutil::RED);
            waitkey;
            break;
        }
        default: {
            rlutil::setColor(rlutil::RED);
            std::cout << "Incorrect option!\n";
            login();
            break;
        }
    }
}

bool Interface::loginUser(const std::string& userOrEmail, const std::string& pass, const std::string& fileName) {
    std::ifstream in(fileName);
    std::string username, password, email, name;
    // de implementat logale cu supraincarcare>>
    while(in) {
        std::getline(in, username, ';');
        std::getline(in, password, ';');
        std::getline(in, email, ';');
        std::getline(in, name);
        if((username == userOrEmail || email == userOrEmail) && password == pass)
        {
            //std::cout << "buna, " << name << "!";
            return true;
        }
    }
    return false;
}

bool Interface::loginAdmin(const std::string& userOrEmail, const std::string& pass, const std::string& fileName) {
    std::ifstream in(fileName);
    std::string username, password, name, email;
    // de implementat logale cu supraincarcare>>
    while(in) {
        std::getline(in, username, ';');
        std::getline(in, password, ';');
        std::getline(in, email);

        if((username == userOrEmail || email == userOrEmail) && password == pass) return true;
    }
    return false;
}

/** VALIDATION METHODS **/

/* Function that checks if the two passwords are the same */
bool Interface::checkPass(const std::string& pass1, const std::string& pass2) {
    return pass1 == pass2;
}

/* Function that checks if the username contains any spaces */
bool Interface::checkUsername(const std::string& username) {
    return username.find(' ') == std::string::npos;
}

/* Function that checks if the email contains 'at' char */
bool Interface::checkEmail(const std::string& email) {
    return email.find('@') != std::string::npos;
}

/** LOADING DATA METHODS **/

void Interface::loadUsersData(const std::string& fileName, std::vector<User>& users) {
    std::ifstream fin(fileName);
    std::string username, password, email;

    while(!fin.eof()) {
        fin >> username >> password >> email;
        User temp(username, password, email);
        users.push_back(temp);
    }

    fin.close();
}

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