#include <iostream>
#include <string>

void computeCoin(int coinValue, int &number, int &amountLeft) {
    unsigned char coincount = amountLeft / coinValue; // Calculate the number of coins. Rounded down
    number += coincount; // Add the number of coins to the total number of coins
    amountLeft -= coincount * coinValue; // Subtract the value of the coins from the total amount
}

struct CashRegister {
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
};

int main()
{
    std::string continue_str;
    do {
        int amount;
        CashRegister reg;

        std::cout << "Enter the amount of money: ";
        std::cin >> amount;

        computeCoin(25, reg.quarters, amount);
        computeCoin(10, reg.dimes, amount);
        //computeCoin(5, reg.nickels, amount); // Not computing nickels
        computeCoin(1, reg.pennies, amount);

        std::cout << "Quarters: " << reg.quarters << std::endl;
        std::cout << "Dimes: " << reg.dimes << std::endl;
        //std::cout << "Nickels: " << reg.nickels << std::endl; // Not computing nickels
        std::cout << "Pennies: " << reg.pennies << std::endl;

        std::cout << "Type anything to exit, or Y to run again...";
        std::cin >> continue_str;
    } while (continue_str == "Y" || continue_str == "y");

    return 0;
}