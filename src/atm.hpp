// @fpetrovicc, 2021.
#include <limits>
#include <ctime>

struct Balance {
    int card;
    int cash;
};

// TODO - Improve RNG
int randomNum(int min, int max)
{
    srand(time(0));
    return (rand() % (max + 1 - min) + min);
}

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
void checkBalance(int& cardBal, int& cashBal)
{
    Clear();
    std::cout << "ATM Simulator" << std::endl;
    std::cout << "=============" << std::endl;
    std::cout << "Your card balance is: " << cardBal << std::endl;
    std::cout << "Your cash balance is: " << cashBal << std::endl;
    std::cout << "\n[Press any key to continue]";
    std::cin.get();
}

// TODO - Withdrawal function
void withdraw(int& cardBal, int& cashBal)
{
    int choice = 0;
    Clear();
    std::cout << "ATM Simulator" << std::endl;
    std::cout << "=============" << std::endl;
    std::cout << "Card balance: " << cardBal << std::endl;
    std::cout << "How much do you want to withdraw?: ";
    choice = getInput(1, cardBal);

    std::cout << "Transaction: " << choice << " -> Cash balance " << std::endl;
    cardBal -= choice;
    cashBal += choice;

    std::cout << "\nNew card balance: " << cardBal << std::endl;
    std::cout << "New cash balance: " << cashBal << std::endl;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n[Press any key to continue]";
    std::cin.get();
}

// TODO - Deposit function
void deposit(int &cardBal, int &cashBal)
{
    int choice = 0;
    Clear();
    std::cout << "ATM Simulator" << std::endl;
    std::cout << "=============" << std::endl;
    std::cout << "Cash balance: " << cashBal << std::endl;
    std::cout << "How much do you want to deposit?: ";
    choice = getInput(1, cashBal);

    std::cout << "Transaction: " << choice << " -> Card balance " << std::endl;
    cardBal += choice;
    cashBal -= choice;

    std::cout << "\nNew card balance: " << cardBal << std::endl;
    std::cout << "New cash balance: " << cashBal << std::endl;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n[Press any key to continue]";
    std::cin.get();
}