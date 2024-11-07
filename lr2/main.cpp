#include "./Tests/TestModule.h"
#include <cstdlib>


// Run with --std=c++23 -Wl,--stack,16777216

int main()
{
    system("chcp 65001");
    std::cout << std::endl;

    FullCheck();

    return 0;
}