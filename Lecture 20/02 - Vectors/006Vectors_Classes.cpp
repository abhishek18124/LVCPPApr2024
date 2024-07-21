#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

// return true if you want a to be ordered before b otherwise return false

bool ageComparator(customer a, customer b) {

	if (a.age < b.age) {

		// we want a to be ordered before b since we are sorting in the inc. ordere based on age

		return true;

	}

	return false;

}

class AgeComparator {

public:

	// return true if you want a to be ordered before b otherwise return false

	bool operator()(customer a, customer b) {

		if (a.age < b.age) {

			// we want a to be ordered before b since we are sorting in the inc. ordere based on age

			return true;

		}

		return false;

	}

};

// return true if you want a to be ordered before b otherwise return false

bool creditsComparator(customer a, customer b) {

	if (a.credits > b.credits) {

		// we want a to be ordered before b since we are sorting in the dec. ordere based on credits

		return true;

	}

	return false;

}

int main() {

	vector<customer> v;

	v.push_back(customer("Ramanujan", 32, 'M', 1729));
	v.push_back(customer("JC Bose", 78, 'M', 2500));
	v.push_back(customer("Aryabhata", 74, 'M', 0));
	v.push_back(customer("Vikram", 52, 'M', 1500));
	v.push_back(customer("Homi", 56, 'M', 1000));

	// sort(v.begin(), v.end(), ageComparator); // ageComparator(a, b)

	AgeComparator obj;

	sort(v.begin(), v.end(), obj); // obj(a, b)

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	cout << endl;

	sort(v.begin(), v.end(), creditsComparator);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}


	return 0;
}