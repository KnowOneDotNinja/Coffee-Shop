/******************************************************************************
# Author:           Mike Winebarger
# Lab:              Assignment 7
# Date:             November 17, 2021
# Description:      This program simulates an online ordering system for a
                    coffee shop
# Input:            int menuChoice, char itemChoice, int tipChoice
# Output:           integer birth year
# Sources:          None
#******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

const double DONUT_PRICE = 4.00;
const double MUFFIN_PRICE = 4.50;
const double PASTRY_PRICE = 5.50;
const double BAGEL_PRICE = 3.75;
const double TOAST_PRICE = 2.25;
const double COFFEE_PRICE = 3.50;
const double TEA_PRICE = 2.50;
const double TIP_15 = 0.15;
const double TIP_20 = 0.20;
const double TIP_25 = 0.25;


int main() {

    int menuChoice = 0;
    char itemChoice = ' ';
    char shopAgain = 'y';
    double orderTotal = 0.0;
    double tipAmt = 0.0;

    cout << "Welcome to the Coffee Shop!" << endl << endl;

    do {
       
        cout << "Please pick an option below:" << endl << endl;
        cout << "  1.  Donuts/Muffins/Pastry" << endl;
        cout << "  2.  Bagels/Toast" << endl;
        cout << "  3.  Coffee/Tea" << endl;
        cout << "  4.  Quit" << endl;
        cout << ">> ";
        //cin >> menuChoice;

        if (cin >> menuChoice) {

            switch (menuChoice) {
            case 1:
                cout << "Please choose an item (D, M or F):" << endl << endl;
                cout << "  D: Donut  - $" << fixed << setprecision(2) << DONUT_PRICE << endl;
                cout << "  M: Muffin - $" << fixed << setprecision(2) << MUFFIN_PRICE << endl;
                cout << "  P: Pastry - $" << fixed << setprecision(2) << PASTRY_PRICE << endl;
                cout << ">> ";
                cin >> itemChoice;
                itemChoice = tolower(itemChoice);

                switch (itemChoice) {
                case 'd':
                    orderTotal += DONUT_PRICE;
                    cout << "Your total is: $" << fixed << setprecision(2) << orderTotal;
                    cout << "\nWould you like to add another item (y/n): ";
                    cin >> shopAgain;
                    if (shopAgain == 'y') {
                        continue;
                    }
                    else {
                        break;
                    }
                case 'm':
                    orderTotal += MUFFIN_PRICE;
                    cout << "Your total is: $" << fixed << setprecision(2) << orderTotal;
                    cout << "\nWould you like to add another item (y/n): ";
                    cin >> shopAgain;
                    if (shopAgain == 'y') {
                        continue;
                    }
                    else {
                        break;
                    }

                case 'p':
                    orderTotal += PASTRY_PRICE;
                    cout << "Your total is: $" << fixed << setprecision(2) << orderTotal;
                    cout << "\nWould you like to add another item (y/n): ";
                    cin >> shopAgain;
                    if (shopAgain == 'y') {
                        continue;
                    }
                    else {
                        break;
                    }
                
                default:
                    cout << "Invalid choice, returning to main menu!" << endl;
                    continue;
                }

            case 2:
                cout << "Please choose an item (B or T): " << endl << endl;
                cout << "  B: Bagel  - $" << fixed << setprecision(2) << BAGEL_PRICE << endl;
                cout << "  T: Toast - $" << fixed << setprecision(2) << TOAST_PRICE << endl;
                cout << ">> ";
                cin >> itemChoice;
                itemChoice = tolower(itemChoice);
                
                switch (itemChoice) {
                case 'b':
                    orderTotal += BAGEL_PRICE;
                    cout << "Your total is: $" << fixed << setprecision(2) << orderTotal;
                    cout << "\nWould you like to add another item (y/n): ";
                    cin >> shopAgain;
                    if (shopAgain == 'y') {
                        continue;
                    }
                    else {
                        break;
                    }
                case 't':
                    orderTotal += TOAST_PRICE;
                    cout << "Your total is: $" << fixed << setprecision(2) << orderTotal;
                    cout << "\nWould you like to add another item (y/n): ";
                    cin >> shopAgain;
                    if (shopAgain == 'y') {
                        continue;
                    }
                    else {
                        break;
                    }
                default:
                    cout << "Invalid input, returning to main menu!" << endl;
                    continue;
                }
            case 3:
                cout << "Please choose an item (C or T): " << endl << endl;
                cout << "  C: Coffee  - $" << fixed << setprecision(2) << COFFEE_PRICE << endl;
                cout << "  T: Tea - $" << fixed << setprecision(2) << TEA_PRICE << endl;
                cout << ">> ";
                cin >> itemChoice;
                itemChoice = tolower(itemChoice);

                switch (itemChoice) {
                case 'c':
                    orderTotal += COFFEE_PRICE;
                    cout << "Your total is: $" << fixed << setprecision(2) << orderTotal;
                    cout << "\nWould you like to add another item (y/n): ";
                    cin >> shopAgain;
                    if (shopAgain == 'y') {
                        continue;
                    }
                    else {
                        break;
                    }
                case 't':
                    orderTotal += TEA_PRICE;
                    cout << "Your total is: $" << fixed << setprecision(2) << orderTotal;
                    cout << "\nWould you like to add another item (y/n): ";
                    cin >> shopAgain;
                    if (shopAgain == 'y') {
                        continue;
                    }
                    else {
                        break;
                    }
                default:
                    cout << "Invalid input, returning to main menu!" << endl;
                    continue;
                }
            
            default:
                break;
            }
        }
        else {
            cout << "Invalid input, try again!" << endl << endl;
            cin.clear();
            cin.ignore();
            continue;
             
        }
    } while (shopAgain == 'y');

    cout << "Your total is: $" << fixed << setprecision(2) << orderTotal << endl;
    cout << "Would you like to add a tip? Suggested amounts:" << endl;
    cout << "15% = " << fixed << setprecision(2) << orderTotal * TIP_15 << endl;
    cout << "20% = " << fixed << setprecision(2) << orderTotal * TIP_20 << endl;
    cout << "25% = " << fixed << setprecision(2) << orderTotal * TIP_25 << endl;
    cout << endl << "Enter tip amount: ";
    
    cin >> tipAmt;
    orderTotal += tipAmt;
    cout << "\nPlease pay: $" << fixed << setprecision(2) << orderTotal << endl;
    cout << "\nThank you for eating at Coffee Shop!";

}