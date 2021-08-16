// include
#include "include/Interface.h"

int main() {
    Interface* i = Interface::getInstance();
    i->startApp();
    std::cin.get();
    return 0;
}
