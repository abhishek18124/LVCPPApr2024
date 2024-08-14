/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public:

	string name;
	int age;
	double credits;

	customer(string name, int age, double credits) {
		this->name = name;
		this->age = age;
		this->credits = credits;
	}
};

class ageComparator {

public:

	// // return true if you want a to be ordered before b otherwise return false

	// bool operator()(customer a, customer b) {

	// 	if (a.age < b.age) {

	// 		// we want a to be ordered before b since we are building a minHeap based on age

	// 		return true;

	// 	}

	// 	return false;

	// }

	// return true if you want a to be given lower priority than b otherwise return false

	// return false if you want a to be given higher priority than b otherwise return true

	bool operator()(customer a, customer b) {

		if (a.age < b.age) {

			// we want a to be given more priority than b since we are building a minHeap based on age

			return false;

		}

		return true;

	}

};

class creditsComparator {

public:

	// return false if you want a to be given more priority than b otherwise return true

	bool operator()(customer a, customer b) {

		if (a.credits > b.credits) {

			return false;

		}

		return true;

	}

};

int main() {

	// priority_queue<customer, vector<customer>, ageComparator> m; // we are trying to create a minHeap based on cusomerAge
	priority_queue<customer, vector<customer>, creditsComparator> m; // we are trying to create a maxHeap based on cusomerCredits

	m.push(customer("Shiv", 19, 1000));
	m.push(customer("Harsh", 20, 500));
	m.push(customer("Yashika", 18, 750));
	m.push(customer("Abrar", 21, 2500));

	cout << m.size() << endl;

	while (!m.empty()) {

		customer c = m.top();
		m.pop();

		cout << c.name << " " << c.age << " " << c.credits << endl;

	}

	cout << m.size() << endl;

	return 0;
}