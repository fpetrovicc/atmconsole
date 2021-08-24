// @fpetrovicc, 2021.
#include <iostream>
#include "atm.hpp"

int main()
{
    int choice;
    balance test;
    test.cash = 5;

    startScreen();

    while (true) {
        choice = mainScreen();
        if (choice == -1)
        {
            mainScreen();
            continue;
        }

        else
        {
            std::cin.ignore();
            break;
        }
    }
    
    //Debug
    std::cin.get();
    return 0;

}
