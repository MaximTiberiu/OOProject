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
    //system("cls");
}

void Interface::signup() {
    //system("cls");
}

void Interface::signupAdmin(const std::string fileName) {
    std::ofstream out;
    out.open(fileName, std::ios::app);

    std::string username, pass1, pass2, email;

    std::cout << "Username: ";
    std::getline(std::cin, username);

    std::cout << "Email: ";
    std::getline(std::cin, email);

    std::cout << "Password: ";
    std::getline(std::cin, pass1);

    std::cout << "Confirm Password: ";
    std::getline(std::cin, pass2);

    if(checkPass(pass1, pass2)) {
        Admin temp(username, pass1, email);
        admins.insert(it, temp);
        ++it;
    }

    out << username << " " << email << pass1 << "\n";

    out.close();
}

void Interface::signupUser(const std::string fileName) {
    std::ofstream out;
    out.open(fileName, std::ios::app);
    out << "test";
    out.close();
}

bool Interface::checkPass(const std::string& pass1, const std::string& pass2) {
    if(pass1 == pass2) return true;
    return false;
}