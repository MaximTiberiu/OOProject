// include
#include <iostream>
#include "include/User.h"
#include "include/Interface.h"

int main() {

    /*User u1("MaximTiberiu", "test123", "tiberiu@test.ro");
    std::cout << u1.getUsername() << "\n";
    std::cout << u1.getPassword() << "\n";
    std::cout << u1.getEmail() << "\n";

    u1.setUsername("MaximTiberiu1");
    std::cout << u1.getUsername() << "\n";*/

    Interface i;
    //i.startApp();
    i.signupAdmin("../appFiles/admins.txt");
    i.signupAdmin("../appFiles/admins.txt");

    return 0;
}
