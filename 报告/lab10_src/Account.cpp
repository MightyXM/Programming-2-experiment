#include"Account.h"
#include<iostream>
using namespace std;

void Account::set_value() {
	cout << "Enter Details:" << endl;
	cout << "----------------------------" << endl;
	cout << "Account No. ";
	cin >> account;
	cout << "Name: ";
	cin >> name;
	cout << "Accout Type: ";
	cin >> type;
	cout << "Balance: ";
	cin >> money;
}

void Account::save(int a) {
	money += a;
}
void Account::withdraw(int a) {
	if (money >= a)
		money -= a;
	else cout << "Failed,there is not enough balance.\n";
}

void Account::show() {
	cout << "Account No. " << account << endl;
	cout << "Name: " << name << endl;
	cout << "Account type: " << type << endl;
	cout << "Balance: " << money << endl;
}