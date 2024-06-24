#include<iostream>

using namespace std;

class customer {

public :

	string* namePtr;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "\ninside the parameterised constructor of the \'customer\' class\n" << endl;
		namePtr = new string;
		*namePtr = n;
		age = a;
		gender = g;
		credits = c;
	}

	string getName() {
		return *namePtr;
	}

	void setName(string n) {
		*namePtr = n;
	}

	void print() {
		cout << "name = " << *namePtr << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}

};

int main() {

	customer c1("Ramanujan", 32, 'M', 1729);
	c1.print();

	customer c2 = c1; // default copy constructor is used to make c2 as a copy of c1
	c2.print();

	c2.age = 40;
	c2.credits = 1000;

	c2.print();

	c1.print();

	c2.setName("Aryabhata");

	cout << c1.getName() << endl;
	cout << c2.getName() << endl;

	return 0;
}