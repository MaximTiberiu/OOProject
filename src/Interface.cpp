#include "../include/Interface.h"
#include "../rlutil/rlutil.h"
#include <iostream>

#define waitkey rlutil::anykey("Press any key to continue...\n")

void Interface::startApp() {
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
            startApp();
            break;
        }
    }
}

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
            signup();
            break;
        }
    }
}

void Interface::signupAdmin(const std::string& fileName) {
    auto itA = admins.begin();
    std::ofstream out;
    out.open(fileName, std::ios::app);

    std::string username, pass1, pass2, email;
    bool cond;

    std::cout << "Username: ";
    std::cin.ignore(100, '\n');

    std::getline(std::cin, username);
    cond = checkUsername(username);

    while(!cond) {
        std::cout << "White-spaces are not allowed in username! Please try again!\n";

        std::cout << "Username: ";
        std::getline(std::cin, username);
        cond = checkUsername(username);
    }

    std::cout << "Email: ";
    std::getline(std::cin, email);
    cond = checkEmail(email);

    while(!cond) {
        std::cout << "Invalid email address. Please try again!\n";

        std::cout << "Email: ";
        std::getline(std::cin, email);
        cond = checkEmail(email);
    }

    std::cout << "Password: ";
    std::getline(std::cin, pass1);
    std::cout << "Confirm Password: ";
    std::getline(std::cin, pass2);
    cond = checkPass(pass1, pass2);

    while(!cond)
    {
        std::cout << "Those passwords didn't match. Please try again!\n";

        std::cout << "Password: ";
        std::getline(std::cin, pass1);
        std::cout << "Confirm Password: ";
        std::getline(std::cin, pass2);
        cond = checkPass(pass1, pass2);
    }

    Admin temp(username, pass1, email);
    admins.insert(itA, temp);
    ++itA;

    out << temp;

    out.close();
}

void Interface::signupUser(const std::string& fileName) {
    auto itU = users.begin();

    std::ofstream out;
    out.open(fileName, std::ios::app);

    std::string username, pass1, pass2, email, name;
    std::string dummy;
    bool cond;

    std::cout << "Name: ";
    std::cin.ignore(100, '\n');

    std::getline(std::cin, name);

    std::cout << "Username: ";
    std::getline(std::cin, username);
    cond = checkUsername(username);

    while(!cond) {
        std::cout << "White-spaces are not allowed in username! Please try again!\n";

        std::cout << "Username: ";
        std::getline(std::cin, username);
        cond = checkUsername(username);
    }

    std::cout << "Email: ";
    std::getline(std::cin, email);
    cond = checkEmail(email);

    while(!cond) {
        std::cout << "Invalid email address. Please try again!\n";

        std::cout << "Email: ";
        std::getline(std::cin, email);
        cond = checkEmail(email);
    }

    std::cout << "Password: ";
    std::getline(std::cin, pass1);
    std::cout << "Confirm Password: ";
    std::getline(std::cin, pass2);
    cond = checkPass(pass1, pass2);

    while(!cond)
    {
        std::cout << "Those passwords didn't match. Please try again!\n";

        std::cout << "Password: ";
        std::getline(std::cin, pass1);
        std::cout << "Confirm Password: ";
        std::getline(std::cin, pass2);
        cond = checkPass(pass1, pass2);
    }

    User temp(name, username, pass1, email);
    users.insert(itU, temp);
    ++itU;

    out << temp;

    out.close();
}

bool Interface::checkPass(const std::string& pass1, const std::string& pass2) {
    if(pass1 == pass2) return true;
    return false;
}

bool Interface::checkUsername(const std::string& username) {
    for(char i : username)
        if(i == ' ') return false;
    return true;
}

bool Interface::checkEmail(const std::string& email) {
    return email.find('@') != std::string::npos;
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