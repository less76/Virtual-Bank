#include "Bank.h"
#include <string>
#include <iostream>
#include <ctime>    
#include <sstream>
#include <cstdlib>  
using namespace std;

Bank::Bank() {
	description_size = 0;

	for (int i = 0; i < 3; i++)
		description[i] = NULL;
}

Bank::Bank(const Bank &copy) {

	for (int i = 0; i < 3; i++) {
		description[i] = copy.description[i];
	}

	this->Entry_t.change_t.name = "";
	this->Entry_t.change_t.totalplus = "";
	this->Entry_t.change_t.totalminus = "";
	this->Entry_t.change_t.account_number = "";
	this->remove = "";
}

Bank::~Bank() {

	for (int i = 0; i < 3; i++)
		delete[]description[i];

}

void Bank::set_description_size(int description_size) {
	this->description_size = description_size;
}

int Bank::get_description_size() {
	return description_size;
}

void Bank::set_removal(std::string remove) {
	this->remove = remove;
}

std::string Bank::get_removal() {
	return this->remove;
}

void Bank::addEntrydescription() {

	std::string *new_array = new std::string[get_description_size() + 1];

	if (get_description_size() == 0) {
		*new_array = this->Entry_t.name;
		description[0] = new_array;
	}

	else {

		for (int i = 0; i < get_description_size(); i++) {
			*new_array++ = *description[0]++;
		}

		*new_array = this->Entry_t.name;
		new_array -= get_description_size();

		description[0] = new_array;

	}

}

void Bank::editEntry() {
	int found = 0;

	try {
		if (description_size == 0) {
			throw "Cant edit something if there is nothing on the list";
		}
	}

	catch (const char *e) {
		cout << e << endl;
	}

	std::string** new_array = new std::string*[3];

	for (int i = 0; i < 3; i++)
		new_array[i] = new std::string[get_description_size() + 1]; //initialize new string

	for (int i = 0; i < get_description_size(); i++) {

		for (int j = 0; j < 3; j++)
			*new_array[j] = *description[j]++;  //loading to local variable

		if (*new_array[0] == this->Entry_t.change_t.search) { //checking if variable is located

			if (this->Entry_t.change_t.name != "") {
				*new_array[0] = this->Entry_t.change_t.name;
			}

			if (this->Entry_t.change_t.account_number != "") {

					char hold1[10];
					std::string save1 = "";

					for (int i = 0; i < 10; i++) {
						int r = (rand() % 9) + 1;

						hold1[i] = r + 0x30;

					}

					for (int i = 0; i < 10; i++) {
						save1 = save1 + hold1[i];
					}

				*new_array[1] = save1;
			}

			if (this->Entry_t.change_t.totalplus != "" || this->Entry_t.change_t.totalminus != "") {
				int op_flag = 0;
				std::string save = *new_array[2];

				try {

					for (int i = 0; i < this->Entry_t.change_t.totalplus.size(); i++) {
						if ((this->Entry_t.change_t.totalplus[i] < '0' || this->Entry_t.change_t.totalplus[i] > '9') && this->Entry_t.change_t.totalplus[i] != '.') {
							throw "not a number";
						}

						else {
							save = this->Entry_t.change_t.totalplus;
							op_flag = 0;
						}
					}


					for (int i = 0; i < this->Entry_t.change_t.totalminus.size(); i++) {
						if ((this->Entry_t.change_t.totalminus[i] < '0' || this->Entry_t.change_t.totalminus[i] > '9') && this->Entry_t.change_t.totalminus[i] != '.') {
							throw "not a number";
						}

						else {
							save = this->Entry_t.change_t.totalminus;
							op_flag = 1;
						}
					}


				}

				catch (const char *p) {
					cout << p << endl;
				}


				std::string hold = *new_array[2];

				double number1 = atof(save.c_str());
				double number2 = atof(hold.c_str());
				double number3;
				
				number3 = (op_flag == 1) ? number2 - number1 : number2 + number1;
				
				auto num_str = std::to_string(number3);
				remove = num_str;

				*new_array[2] = num_str;  //change data

			}
		}

		for (int j = 0; j < 3; j++) {   //incrementing through each dimension
			new_array[j]++;
		}
	}

	for (int j = 0; j < 3; j++) {
		new_array[j] -= get_description_size();
	}

	for (int j = 0; j < 3; j++) {                  //load to global pointer
		description[j] = new_array[j];
	}

}

void Bank::removeEntrydescription() {

	int found = 0;

	try {
		if (description_size == 0) {
			throw "you need to add something to the list first";
		}
	}

	catch (const char *e) {
		cout << e << endl;
	}

	std::string** new_array = new std::string*[3];
	for (int i = 0; i < 3; i++)
		new_array[i] = new std::string[get_description_size()];

	for (int i = 0; i < get_description_size() - 1; i++) {

		for (int j = 0; j < 3; j++)
			*new_array[j] = *description[j]++; //loading to local variable to check

		if (*new_array[0] == this->Entry_t.name) {
			remove = *new_array[2];               //when string is located the money is loaded to a global variable 

			for (int j = 0; j < 3; j++) {
				*new_array[j] = *description[j]++;  //skip over current variable
			}

			found = 1;                     //check is variable is found flag
		}

		for (int j = 0; j < 3; j++) {     //incrementing through each demenstion
			new_array[j]++;
		}

	}

	if (found == 0 && description_size != 0) {                                  //if flag is not set return to current address
		cout << "Can not find string in list" << endl;

		for (int j = 0; j < 3; j++)
			description[j] -= get_description_size() - 1;
	}

	else {                                           //if found begin each dimension with initial value

		for (int j = 0; j < 3; j++) {
			new_array[j] -= get_description_size() - 1;
		}

		for (int j = 0; j < 3; j++) {                  //load to global pointer
			description[j] = new_array[j];
		}

		if (description_size != 0) {
			description_size--;                    //decrease array size
		}

	}
}

void Bank::addaccount_number() {
	
	char hold[11];
	std::string save = "";
	
	for (int i = 0; i < 10; i++) {
		int r = (rand() % 9) + 1;

		hold[i] = r + 0x30;
		
	}

	for (int i = 0; i < 10; i++) {
		save = save + hold[i];
	}

	std::string *new_array = new std::string[get_description_size() + 1];

	if (get_description_size() == 0) {
		*new_array = save;
		description[1] = new_array;
	}

	else {

		for (int i = 0; i < get_description_size(); i++) {
			*new_array++ = *description[1]++;
		}

		*new_array = save;
		new_array -= get_description_size();

		description[1] = new_array;

	}
}

void Bank::addmoney() {
	std::string save;

	try {

		for (int i = 0; i < this->Entry_t.total.size(); i++) {
			if ((this->Entry_t.total[i] < '0' || this->Entry_t.total[i] > '9') && this->Entry_t.total[i] != '.') {
				throw "not a number";
			}

			else {
				save = this->Entry_t.total;
			}
		}

	}

	catch (const char *p) {
		cout << p << endl;
	}

	std::string *new_array = new std::string[get_description_size() + 1];

	if (get_description_size() == 0) {
		*new_array = save;
		description[2] = new_array;
	}

	else {

		for (int i = 0; i < get_description_size(); i++) {
			*new_array++ = *description[2]++;
		}

		*new_array = save;
		new_array -= get_description_size();

		description[2] = new_array;

	}

	description_size++;

}

void Bank::getEntry() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < get_description_size(); j++) {
			if (i == 2) {
				cout << "$";
			}
			cout << *description[i]++;
			cout << "   ";
		}

		description[i] -= get_description_size();
		cout << " " << endl;
	}
}

std::istream& operator >> (istream& is, Bank& input) {
	is >> input.Entry_t.total;
	return is;
}

std::ostream& operator << (ostream& os, const Bank& output) {

	os << output.Entry_t.total;
	return os;
}

Bank Bank::operator +(Bank& plus) {

	plus.addEntrydescription();
	plus.addaccount_number();
	plus.addmoney();

	double number1 = atof(this->Entry_t.total.c_str());
	double number2 = atof(plus.Entry_t.total.c_str());
	double number3 = number1 + number2;

	auto num_str = std::to_string(number3);
	this->Entry_t.total = num_str;

	return *this;
}

Bank Bank::operator -(Bank& minus) {

	minus.removeEntrydescription();

	double number1 = atof(this->Entry_t.total.c_str());
	double number2 = atof(minus.remove.c_str());
	double number3 = number1 - number2;

	auto num_str = std::to_string(number3);
	this->Entry_t.total = num_str;

	return *this;
}

Bank Bank::operator ^(Bank& edit) {
	edit.editEntry();

	double number1 = atof(this->Entry_t.total.c_str());
	double number2 = atof(edit.remove.c_str());
	double number3 = number1 - number2;

	auto num_str = std::to_string(number3);
	this->Entry_t.total = num_str;

	return *this;
}