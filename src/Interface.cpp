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
    std::ofstream out(fileName);
    out << "test";
}

void Interface::signupUser(const std::string fileName) {
    std::ofstream out(fileName);
    out << "test";
}