#include"Account.h"
#include<iostream>
using namespace std;
int main() {
	Account a;
	a.set_value();
	int despoit, wd;
	cout << "Enter Despoit Amount = ";
	cin >> despoit;
	cout << "Enter Withdraw Amount = ";
	cin >> wd;
	cout << "---------------------------------" << endl;
	a.save(despoit);
	a.withdraw(wd);
	a.show();
}