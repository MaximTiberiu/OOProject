#include "../include/Interface.h"
#include "../rlutil/rlutil.h"
#include <iostream>
#include <chrono>
#include <thread>

#define waitkey rlutil::anykey("Press any key to continue...\n")


/* Function that opens the app. */
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

    User temp(username, encryptPass(pass1, key), email);
    users.push_back(temp);

    rlutil::setColor(rlutil::YELLOW);
    std::cout << "Your account has been successfully created! Please wait...\n";
    std::this_thread::sleep_for(std::chrono::seconds (5));
    out << temp;
    out.close();
    startApp();
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
                  std::this_thread::sleep_for(std::chrono::milliseconds(15));
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
                    std::this_thread::sleep_for(std::chrono::milliseconds(15));
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

bool Interface::loginUser(const std::string& userOrEmail, const std::string& pass, const std::string& fileName, User& user) {
    for(auto &us : users)
        if((userOrEmail.compare(us.getUsername()) == 0 || userOrEmail.compare(us.getEmail()) == 0) && encryptPass(pass, key).compare(us.getPassword()) == 0){
            user = us;
            return true;
        }
    return false;
}

bool Interface::loginAdmin(const std::string& userOrEmail, const std::string& pass, const std::string& fileName, Admin& admin) {
    for(auto &ad : admins)
        if((userOrEmail.compare(ad.getUsername()) == 0 || userOrEmail.compare(ad.getEmail()) == 0) && encryptPass(pass, key).compare(ad.getPassword()) == 0){
            admin = ad;
            return true;
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

bool Interface::checkDuplicateUsername(const std::string& username) {
    for(auto &us : users)
        if(username.compare(us.getUsername()) == 0) return false;

    for(auto &ad : admins)
        if(username.compare(ad.getUsername()) == 0) return false;
    return true;
}

bool Interface::checkDuplicateEmail(const std::string& email) {
    for(auto &us : users)
        if(email.compare(us.getEmail()) == 0) return false;

    for(auto &ad : admins)
        if(email.compare(ad.getEmail()) == 0) return false;
    return true;
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

    for(auto & user : users)
        std::cout << user.getUsername() << " ";
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

void Interface::panel(User& user) {
    rlutil::cls();
    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Bine ai venit, " << user.getUsername() <<"!\n";
    std::cout << "-------------------------------------------------\n\n";
    waitkey;
    return;

}

void Interface::panel(Admin& admin) {
    rlutil::cls();
    std::cout << "-------------------------------------------------\n";
    std::cout << "                    Bine ai venit, " << admin.getUsername() <<"!\n";
    std::cout << "-------------------------------------------------\n\n";
    waitkey;
    return;
}

/** SECURITY METHODS **/

std::string Interface::encryptPass(const std::string& password, const char* key) {
    std::string encryptedPass = password;
    for(int i = 0 ; i < encryptedPass.size() ; i++) {
        encryptedPass = password[i] ^ key[i % (sizeof(key) / sizeof(char))];
    }
    return encryptedPass;
}