#pragma once
#include <string>
#include <iostream>
class Bank {
private:
	std::string *description[3];
	int description_size;
	std::string remove;

public:
	Bank();
	Bank(const Bank &copy);
	~Bank();
	void set_description_size(int);
	int get_description_size();
	void set_removal(std::string);
	std::string get_removal();

	struct Entry {
		std::string name;
		std::string total;
		std::string account_number;

		struct change {
			std::string search;
			std::string name;
			std::string totalplus;
			std::string totalminus;
			std::string account_number;
		}change_t;

	}Entry_t;

	void addEntrydescription();
	void removeEntrydescription();
	void editEntry();
	void addaccount_number();
	void addmoney();
	void getEntry();

	Bank operator +(Bank& plus);
	Bank operator -(Bank& minus);
	Bank operator ^(Bank& edit);

	friend std::ostream& operator << (std::ostream& os, const Bank& output);
	friend std::istream& operator >> (std::istream& is, Bank& input);

};