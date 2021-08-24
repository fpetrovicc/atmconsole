#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
// @fpetrovicc, 2021.
#include <iostream>
#include "atm.hpp"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-branch-clone"
int main()
{
    int choice;

    startScreen();

    while (true)
    {
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

        switch(choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                return 0;
        }

        break;
    }

    // Exit
    std::cout << "\n[EXITING (press enter)]";
    std::cin.get();
    return 0;

}