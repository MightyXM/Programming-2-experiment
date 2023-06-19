#include<iostream>
using namespace std;

class Account {
private:
	char name[20];
	char account[10];
	char type[20];
	int money;
public:
	void set_value();
	void show();
	void save(int a);
	void withdraw(int a);
};