//  main.cpp
//  Assignment1
//  Created by Travis Cassell on 2/20/21.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // VARIABLES FOR COIN VALUES
    double FIVE = 5.00,         // Value of 5 dollars
           DOLLAR = 1.00,       // Value of 1 dollar
           QUARTER = 0.25,      // Value of quarter
           DIME = 0.10,         // Value of dime
           NICKEL = 0.05;       // Value of nickel

    // CONSTANTS FOR MENU CHOICES
    const int FIVE_DEPOSIT = 1,
              ONE_DEPOST = 2,
              QUARTER_DEPOSIT = 3,
              DIME_DEPOSIT = 4,
              NICKEL_DEPOSIT = 5,
              QUIT = 6;

    // VARIABLES FOR STOCK CONTENTS
    int fives = 0,                 // Stock of fives
        ones = 0,                  // Stock of ones
        quarters = 25,             // Stock of quarters
        dimes = 25,                // Stock of dimes
        nickels = 25;              // Stock of nickels
    
    // PLACEHOLDING VARIABLES FOR COIN RETURN
    int tempQuarters = 0,
        tempDimes = 0,
        tempNickels = 0;
    
    // VARIABLE TO HOLD USER CHOICE
    int choice;

    // VARIABLE TO HOLD USER DECISION
    bool again;
    again = true;

    // SET UP NUMERIC OUTPUT FORMATTING
    cout << fixed << showpoint << setprecision(2);
    
    // DISPLAY THE CURRENT STOCK OF COINS
    cout << "The current stock of fives is: " << fives << "\n";
    cout << "The current stock of ones is: " << ones << "\n";
    cout << "The current stock of quarters is: " << quarters << "\n";
    cout << "The current stock of dimes is: " << dimes << "\n";
    cout << "The current stock of nickels is: " << nickels << "\n\n";
    
    do
    {
        // VARIABLES TO STORE PRICE AND CURRENT DEPOSIT
        double deposit = 0,
               price = 0;
        
        cout << "\nEnter the price of your choice in dollars and coins in the form $00.00\n\n";
        cin >> price;
        
        float tempVal = price * 100;
        unsigned int x = tempVal;

        while (price < 0 || x % 5 != 0)
        {
            cout << "\nError! Enter a price in the format $00.00\n\n";
            cin >> price;
            tempVal = price * 100;
            x = tempVal;
        }
        

        cout << "\nYour price is: $" << price << "\n\n";
        cout << "Make your deposit one bill or coin at a time. \n\n";
    
        do{
            // DISPLAY THE MENU OPTIONS
            cout << "Select from the following menu: \n\n"
                 << "'1' for a five dollar bill \n"
                 << "'2' for a one dollar bill \n"
                 << "'3' for a quarter \n"
                 << "'4' for a dime \n"
                 << "'5' for a nickel \n"
                 << "'6' to quit the program \n\n";
            cin >> choice;
        
            // VALIDATE THE MENU OPTIONS
            while (choice < FIVE_DEPOSIT || choice > QUIT)
            {
                cout << "Please enter a valid choice from the menu: \n";
                cin >> choice;
            }
            if (deposit < price)
            {
                switch (choice)
                {
                    case FIVE_DEPOSIT:
                        deposit += FIVE;
                        fives += 1;
                        break;
                    case ONE_DEPOST:
                        deposit += DOLLAR;
                        ones += 1;
                        break;
                    case QUARTER_DEPOSIT:
                        deposit += QUARTER;
                        quarters += 1;
                        break;
                    case DIME_DEPOSIT:
                        deposit += DIME;
                        dimes += 1;
                        break;
                    case NICKEL_DEPOSIT:
                        deposit += NICKEL;
                        nickels += 1;
                    case QUIT:
                        price = 0;
                        break;
                }
                cout << "\n";
                cout << "Current deposit is: $" << deposit << "\n";
                if (deposit >= price || price == 0)
                    break;
                cout << "\nYou owe: $" << (price - deposit) << "\n";
                cout << "\n";
            }
        } while (choice != QUIT && deposit < price);
        
        // IF EXACT CHANGE PAID
        if (deposit == price)
            cout << "\nNo change due\n";
        
        // MAKE CHANGE
        
        double changeOwed = deposit - price;
        
        if (changeOwed > 0)
        {
            tempQuarters = (changeOwed / QUARTER);
            if (tempQuarters > quarters)
                tempQuarters = quarters;
            
            double x = tempQuarters * QUARTER;
            changeOwed -= x;
            quarters -= tempQuarters;
        }
        if (changeOwed > 0)
        {
            tempDimes = (changeOwed / DIME);
            if (tempDimes > dimes)
                tempDimes = dimes;
            
            double y = tempDimes * DIME;
            changeOwed -= y;
            dimes -= tempDimes;
        }
        if (changeOwed > 0)
        {
            tempNickels = (changeOwed / NICKEL);
            if (tempNickels > nickels)
                tempNickels = nickels;
            
            double z = tempNickels * NICKEL;
            changeOwed -= z;
            nickels -= tempNickels;
        }
        
        cout << "\nYour change is: $" << ((deposit - price) - changeOwed) << "\n";
        
        if (tempQuarters > 0)
            cout << "\nYou will recieve " << tempQuarters << " quarters\n";
        
        if (tempDimes > 0)
            cout << "You will recieve " << tempDimes << " dimes\n";
        
        if (tempNickels > 0)
            cout << "You will recieve " << tempNickels << " nickels\n";
            
        if (changeOwed > 0)
        {
            cout << "\nWe are unable to dispense your full refund.\n";
            cout << "\nPlease see the manager for the remainder of your change: $" << changeOwed << "\n";
        }
                
        cout << "\nThere are " << fives << " fives in stock";
        cout << "\nThere are " << ones << " dollars in stock";
        cout << "\nThere are " << quarters << " quarters in stock";
        cout << "\nThere are " << dimes << " dimes in stock";
        cout << "\nAnd there are " << nickels << " nickels in stock";
        cout << "\n\nThank you for your visiting! \n";
        cout << "\nWould you like to make another purchase? \n\n";
        cout << "Enter 'Y' for yes and 'N' for no: \n\n";
        
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            again = true;
        else if (answer == 'n' || answer == 'N')
            again = false;
        else
        {
            again = false;
            cout << "\nInvalid answer. Please start over.\n\n";
        }
            
    } while (again == true);
    cout << "\nGoodbye!\n";
    return 0;
    
}




