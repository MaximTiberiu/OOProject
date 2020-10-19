#include "../include/Interface.h"

void Interface::startApp() {
    std::cout << "\t\t\t\tReddit++\n";

    std::cout << "LOG IN - 1\nSIGN UP - 2\n\n";

    std::cin >> opt;

    if(opt == 1)
        login();
    else
        signup();
}

void Interface::login() {
    system("cls");
    std::cout << "\t\t\t\tReddit++\n";

    std::cout << "USER - 1\nADMIN - 2\n\n";

    std::cin >> opt;

    /*if(opt == 1)
        loginUser(userFile);
    else
        loginAdmin(adminFile);*/
}

void Interface::signup() {
    system("cls");
    std::cout << "\t\t\t\tReddit++\n";

    std::cout << "USER - 1\nADMIN - 2\n\n";

    std::cin >> opt;

    if(opt == 1)
        signupUser(userFile);
    else
        signupAdmin(adminFile);
}

void Interface::signupAdmin(const std::string& fileName) {
    std::ofstream out;
    out.open(fileName, std::ios::app);

    std::string username, pass1, pass2, email;
    bool cond;

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

    Admin temp(username, pass1, email);
    admins.insert(itA, temp);
    ++itA;

    out << temp;

    out.close();
}

void Interface::signupUser(const std::string& fileName) {
    std::ofstream out;
    out.open(fileName, std::ios::app);

    std::string username, pass1, pass2, email, name;
    bool cond;

    std::cout << "Name: ";
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
    return email.find("@") != std::string::npos;
}