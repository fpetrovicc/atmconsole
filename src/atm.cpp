// @fpetrovicc, 2021.
#include <iostream>
#include "atm.hpp"

int main()
{
    int choice;
    struct Balance balance = {0, 0};
    struct Balance *bal = &balance;

    balance.card = randomNum(1, 300);
    balance.cash = randomNum(1, 100);

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
            default:
                break;
            case 1:
                checkBalance(bal->card, bal->cash);
                continue;
            case 2:
                deposit(bal->card, bal->cash);
                continue;
            case 3:
                withdraw(bal->card, bal->cash);
                continue;
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