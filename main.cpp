// include
#include "include/User.h"
#include "include/Interface.h"

int main() {
    std::string testFile = "testFile1.txt";

    Interface i;

    std::ifstream fin;
    std::ofstream fout;

    /*Interface::openFile(fin, testFile);
    i.startAppTEST(fin);
    Interface::closeFile(fin);*/

    i.startApp();

    std::cin.get();
    return 0;
}
