/******************************************************************************
# Author:           Mike Winebarger
# Lab:              Assignment 7
# Date:             November 27, 2021
# Description:      This program simulates an online ordering system for a
					coffee shop
# Input:            int menuChoice, char itemChoice, int tipChoice
# Output:           integer birth year
# Sources:          None
#******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;
using namespace std;

const double DONUT_PRICE = 4.00, MUFFIN_PRICE = 4.50, PASTRY_PRICE = 5.50;
const double BAGEL_PRICE = 3.75, TOAST_PRICE = 2.25, COFFEE_PRICE = 3.50;
const double TEA_PRICE = 2.50;
const double TIP_15 = 0.15, TIP_20 = 0.20, TIP_25 = 0.25;

double orderTotal = 0.0;
char shopAgain = 'y';

void welcome();
void displayMenu();
int getChoice();
char anotherItem();
double getItems(int, double);
void output(double);


int main() {

	int choice = 0;

	welcome();

	do {
		displayMenu();
		choice = getChoice();
		orderTotal = getItems(choice, orderTotal);
	} while (choice != 4);

	output(orderTotal);
}


void welcome() {
	cout << "Welcome to the Coffee Shop!" << endl << endl;
}


void displayMenu() {
	cout << "Please pick an option below:" << endl << endl;
	cout << "  1.  Donuts/Muffins/Pastry" << endl;
	cout << "  2.  Bagels/Toast" << endl;
	cout << "  3.  Coffee/Tea" << endl;
	cout << "  4.  Quit" << endl;
}


int getChoice() {
	int choice = 0;
	int menuChoice = 0;

	cout << fixed << showpoint << setprecision(2);
	cout << ">> ";
	cin >> menuChoice;

	while ((!cin) || (menuChoice < 1) || (menuChoice > 4)) {
		cout << "That is not a valid choice (1-4)!" << endl << ">> ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> menuChoice;
	}
	return menuChoice;
}

double getItems(int choice, double orderTotal) {
	char itemChoice = ' ';

	if (choice == 1) {
		cout << "Please choose an item (D, M or F):" << endl << endl;
		cout << "  D: Donut  - $" << DONUT_PRICE << endl;
		cout << "  M: Muffin - $" << MUFFIN_PRICE << endl;
		cout << "  P: Pastry - $" << PASTRY_PRICE << endl;
		cout << ">> ";
		cin >> itemChoice;
		itemChoice = tolower(itemChoice);

		switch (itemChoice) {
		case 'd':
			orderTotal += DONUT_PRICE;
			cout << "Total = " << orderTotal << endl;
			cout << "Your total is: $" << orderTotal;
			shopAgain = anotherItem();
			return orderTotal;
		case 'm':
			orderTotal += MUFFIN_PRICE;
			cout << "Your total is: $" << orderTotal;
			shopAgain = anotherItem();
			if (shopAgain == 'y') {
				return orderTotal;
			}
			else {
				break;
			}

		case 'p':
			orderTotal += PASTRY_PRICE;
			cout << "Your total is: $" << orderTotal;
			shopAgain = anotherItem();
			if (shopAgain == 'y') {
				return orderTotal;
			}
			else {
				break;
			}

		default:
			cout << "Invalid choice, returning to main menu!" << endl;
			return orderTotal;
		}
	}
	else if (choice == 2) {
		cout << "Please choose an item (B or T): " << endl << endl;
		cout << "  B: Bagel  - $" << BAGEL_PRICE << endl;
		cout << "  T: Toast - $" << TOAST_PRICE << endl;
		cout << ">> ";
		cin >> itemChoice;
		itemChoice = tolower(itemChoice);

		switch (itemChoice) {
		case 'b':
			orderTotal += BAGEL_PRICE;
			cout << "Your total is: $" << orderTotal;
			shopAgain = anotherItem();
			if (shopAgain == 'y') {
				return orderTotal;
			}
			else {
				break;
			}
		case 't':
			orderTotal += TOAST_PRICE;
			cout << "Your total is: $" << orderTotal;
			shopAgain = anotherItem();
			if (shopAgain == 'y') {
				return orderTotal;
			}
			else {
				break;
			}
		default:
			cout << "Invalid input, returning to main menu!" << endl;
			return orderTotal;
		}
	}
	else if (choice == 3) {
		cout << "Please choose an item (C or T): " << endl << endl;
		cout << "  C: Coffee  - $" << COFFEE_PRICE << endl;
		cout << "  T: Tea - $" << TEA_PRICE << endl;
		cout << ">> ";
		cin >> itemChoice;
		itemChoice = tolower(itemChoice);

		switch (itemChoice) {
		case 'c':
			orderTotal += COFFEE_PRICE;
			cout << "Your total is: $" << orderTotal;
			shopAgain = anotherItem();
			if (shopAgain == 'y') {
				return orderTotal;
			}
			else {
				break;
			}
		case 't':
			orderTotal += TEA_PRICE;
			cout << "Your total is: $" << orderTotal;
			shopAgain = anotherItem();
			if (shopAgain == 'y') {
				return orderTotal;
			}
			else {
				break;
			}
		default:
			cout << "Invalid input, returning to main menu!" << endl;
			return orderTotal;
		}
	}
	return orderTotal;
}

char anotherItem() {
	cout << "\nWould you like to add another item (y/n): ";
	cin >> shopAgain;

	while (shopAgain != 'y' && shopAgain != 'n') {
		cout << "Not a valid option (y/n)!";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> shopAgain;
	}

	if (shopAgain == 'y') {
		return 'y';
	}
	else {
		return 'n';
	}
}


void output(double OrderTotal) {
	double tipAmt = 0.0;
	cout << fixed << setprecision(2);

	if (orderTotal <= 0) {
		cout << "\nThank you for browsing the Coffee Shop!" << endl;
	}
	else {
		cout << "Your total is: $" << orderTotal << endl;
		cout << "Would you like to add a tip? Suggested amounts:" << endl;
		cout << "15% = " << orderTotal * TIP_15 << endl;
		cout << "20% = " << orderTotal * TIP_20 << endl;
		cout << "25% = " << orderTotal * TIP_25 << endl;
		cout << endl << "Enter tip amount: ";

		cin >> tipAmt;
		orderTotal += tipAmt;
		cout << "\nPlease pay: $" << orderTotal << endl;
		cout << "\nThank you for eating at Coffee Shop!";
	}
}
=======
	int menuChoice = 0;
	char itemChoice = ' ', shopAgain = ' ';
	double orderTotal = 0.0, tipAmt = 0.0;

	cout << "Welcome to the Coffee Shop!" << endl << endl;

	do {

		cout << "Please pick an option below:" << endl << endl;
		cout << "  1.  Donuts/Muffins/Pastry" << endl;
		cout << "  2.  Bagels/Toast" << endl;
		cout << "  3.  Coffee/Tea" << endl;
		cout << "  4.  Quit" << endl;
		cout << ">> ";
		cin >> menuChoice;

		while ((!cin) || (1 > menuChoice) || (menuChoice > 4)) {

			cout << "Invalid option! Please use 1-4." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << ">> ";
			cin >> menuChoice;
		}

		if ((orderTotal > 0) && (menuChoice == 4)) {
			shopAgain = 'n';
			break;
		}

		switch (menuChoice) {
		case 1:
			cout << "\nPlease choose an item (D, M or F):" << endl << endl;
			cout << "  D: Donut  - $" << fixed << setprecision(2) <<
				DONUT_PRICE << endl;
			cout << "  M: Muffin - $" << fixed << setprecision(2) <<
				MUFFIN_PRICE << endl;
			cout << "  P: Pastry - $" << fixed << setprecision(2) <<
				PASTRY_PRICE << endl;
			cout << ">> ";
			cin >> itemChoice;
			itemChoice = tolower(itemChoice);

			switch (itemChoice) {
			case 'd':
				orderTotal += DONUT_PRICE;
				cout << "Your total is: $" << fixed << setprecision(2) << orderTotal
					<< endl;
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
				cout << "Your total is: $" << fixed << setprecision(2) << orderTotal
					<< endl;
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
				cout << "Your total is: $" << fixed << setprecision(2) << orderTotal
					<< endl;
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
				break;
			}
			continue;
		case 2:
			cout << "\nPlease choose an item (B or T): " << endl << endl;
			cout << "  B: Bagel  - $" << fixed << setprecision(2) << BAGEL_PRICE << endl;
			cout << "  T: Toast - $" << fixed << setprecision(2) << TOAST_PRICE << endl;
			cout << ">> ";
			cin >> itemChoice;
			itemChoice = tolower(itemChoice);

			switch (itemChoice) {
			case 'b':
				orderTotal += BAGEL_PRICE;
				cout << "Your total is: $" << fixed << setprecision(2) << orderTotal
					<< endl;
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
				cout << "Your total is: $" << fixed << setprecision(2) << orderTotal
					<< endl;
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
			break;
		case 3:
			cout << "\nPlease choose an item (C or T): " << endl << endl;
			cout << "  C: Coffee  - $" << fixed << setprecision(2) << COFFEE_PRICE << endl;
			cout << "  T: Tea - $" << fixed << setprecision(2) << TEA_PRICE << endl;
			cout << ">> ";
			cin >> itemChoice;
			itemChoice = tolower(itemChoice);

			switch (itemChoice) {
			case 'c':
				orderTotal += COFFEE_PRICE;
				cout << "Your total is: $" << fixed << setprecision(2) << orderTotal
					<< endl;
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
				cout << "Your total is: $" << fixed << setprecision(2) << orderTotal
					<< endl;
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
			break;
		case 4:
			break;

		default:
			cout << "Not a valid input, try again!" << endl;
			continue;
		}

	} while (shopAgain == 'y');

	if (orderTotal > 0) {
		cout << "\nYour total is: $" << fixed << setprecision(2) << orderTotal << endl;
		cout << "\nWould you like to add a tip? Suggested amounts:" << endl;
		cout << "   15% = " << fixed << setprecision(2) << orderTotal * TIP_15 << endl;
		cout << "   20% = " << fixed << setprecision(2) << orderTotal * TIP_20 << endl;
		cout << "   25% = " << fixed << setprecision(2) << orderTotal * TIP_25 << endl;
		cout << endl << "\nEnter tip amount: ";

		cin >> tipAmt;
		orderTotal += tipAmt;
		cout << "\nPlease pay: $" << fixed << setprecision(2) << orderTotal << endl;
		cout << "\nThank you for eating at Coffee Shop!" << endl;
	}
	else {
		cout << "\nThank you for checking out the Coffee Shop!" << endl;
	}
}
