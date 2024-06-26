#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer() {
		cout << "\nI am inside the default constructor of the customer class\n";
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl;
	}
};

int main() {

	customer c1; // default constructor is invoked automatically

	c1.name = "Ramanujan";
	c1.age = 32;
	c1.gender = 'M';
	c1.credits = 1729;

	c1.print();

	customer c2; // default constructor is invoked automatically

	c2.name = "Aryabhata";
	c2.age = 74;
	c2.gender = 'M';
	c2.credits = 0;

	c2.print();

	return 0;
}