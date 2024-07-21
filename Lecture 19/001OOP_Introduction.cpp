#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

};


int main() {

	customer c1; // object declaration

	c1.name = "Abhishek";
	c1.age = 29;
	c1.gender = 'M';
	c1.credits = 0;

	cout << "\ncustomer information\n";
	cout << "name = " << c1.name << endl;
	cout << "age = " << c1.age << endl;
	cout << "gender = " << c1.gender << endl;
	cout << "credits = " << c1.credits << endl << endl;

	customer c2;

	cin >> c2.name;
	cin >> c2.age;
	cin >> c2.gender;
	cin >> c2.credits;

	cout << "\ncustomer information\n";
	cout << "name = " << c2.name << endl;
	cout << "age = " << c2.age << endl;
	cout << "gender = " << c2.gender << endl;
	cout << "credits = " << c2.credits << endl << endl;

	return 0;
}