#include"Rectangle.h"
#include<iostream>
using namespace std;

void Rectangle::set_value() {
	int a,b;
	cout << "输入长度：";
	cin >> a;
	cout << "输入宽度：";
	cin >> b;
	len = a;
	wid = b;
}

int Rectangle::C(void) {
	return (len + wid) * 2;
}

int Rectangle::S(void) {
	return len * wid;
}

void Rectangle::show_value() {
	int c = C();
	int s = S();
	cout << "length: " << len << ' ' << "width: " << wid << ' ' << endl;
	cout << "C: " << c << ' ' << "S: " << s << endl;
}