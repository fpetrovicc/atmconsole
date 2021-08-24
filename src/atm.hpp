// @fpetrovicc, 2021.
#include <limits>

struct balance {
    unsigned int card;
    unsigned int cash;
};

// TODO - 'Random number based on time seed generation' function

void Clear()
{
    #if defined _WIN32
        system("cls");

    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");

    #elif defined (__APPLE__)
        system("clear");
    #endif
}

int getInput(int min, int max)
{
    bool valid = false;
    int num;

    do {
        std::cin >> num;

        if (!(valid = std::cin.good()) ) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (num > min && num < max)
        {
            break;
        }
    } while (!valid);

    return num;
}

void startScreen()
{
    Clear();
    std::cout << "ATM Simulator" << std::endl;
    std::cout << "=============" << std::endl;
    std::cout << "[Chip initialization in progress]" << std::endl;
    std::cout << "[Generating random balance seed]\n" << std::endl;
    std::cout << "[Press any key to continue]";
    std::cin.get();
}

int mainScreen()
{
    int choice = 0;

    Clear();

    std::cout << "ATM Simulator" << std::endl;
    std::cout << "=============" << std::endl;
    std::cout << "(1) Check your balance" << std::endl;
    std::cout << "(2) Deposit your money" << std::endl;
    std::cout << "(3) Withdraw your money" << std::endl;
    std::cout << "(4) Eject the card\n" << std::endl;
    std::cout << "Choose: ";
    choice = getInput(0, 5);

    if (choice > 0 && choice < 5)
        return choice;

    else
        return -1;
}

// TODO - Balance checking function

// TODO - Withdrawal function

// TODO - Deposit function

