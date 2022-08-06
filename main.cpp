#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
#include "Bank.h"

int main()
{

	Bank foods, foods1;
	char option;
	int n = 0;

	while (n != 1) {
		cout << "Welcome to your Bank " << endl;
		cout << "Press a to create a new account" << endl;
		cout << "Press r to remove your account from this bank" << endl;
		cout << "Press q to quit program" << endl;
		cout << "Press e to change something about the account" << endl;
		option = _getch();

		switch (toupper(option)) {

		case 'A':
			cout << "What is your name?" << endl;
			cin >> foods.Entry_t.name;

			//cout << "What is your account number" << endl;
			//cin >> foods.Entry_t.account_number;

			cout << "How much would you like add in this account " << foods.Entry_t.name << endl;
			cin >> foods;
			foods1 + foods;
			break;

		case 'E':
			cout << "Whos name is this account under" << endl;
			cin >> foods.Entry_t.change_t.search;

			//std::string *pointer = foods.getEntry();

			/*try {
				for (int i = 0; i < foods.get_description_size(); i++) {
					if (i == foods.get_description_size() - 1) {
						if (*pointer != foods.Entry_t.change_t.search) {
							throw "cannot find name your searching for";
						}
					}

					pointer++;
				}
			}

			catch (const char *e) {
				cout << e << endl;
			}*/

			cout << "What about this would you like to change" << endl;
			cout << "Press i for name" << endl;
			cout << "Press d to change the account number" << endl;
			cout << "Press p for money" << endl;

			option = _getch();

			switch (toupper(option)) {
			case 'I':
				cout << "What would you like to change this name to? Type then press enter" << endl;
				cin >> foods.Entry_t.change_t.name;
				break;

			case 'D':
				cout << "This is your new account number" << endl;
				foods.Entry_t.change_t.account_number = "dummy";
				break;

			case 'P':
				cout << "How much would you like to make a deposit(d) or withdrawl(w)" << endl;
				option = _getch();

				if (option == 'w') {
					cout << "How much would you like to withdrawl?" << endl;
					cin >> foods.Entry_t.change_t.totalminus;
				}

				if (option == 'd') {
					cout << "How much would you like to deposit?" << endl;
					cin >> foods.Entry_t.change_t.totalplus;
				}
				
				
				break;
			}

			foods1 ^ foods;
			break;

		case 'Q':
			n = 1;
			break;

		case 'R':
			cout << "Whos account would you like to remove" << endl;
			cin >> foods.Entry_t.name;
			foods1 - foods;
			break;
		}

		foods.getEntry();
		//cout << "Your total is $" << foods1 << endl;
	}

	return 0;
}