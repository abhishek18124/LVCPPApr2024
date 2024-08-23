#include<iostream>
#include<unordered_map>

using namespace std;

class customer {

public :

	string name;
	int age;

	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}

	bool operator==(const customer& other) const {
		return this->name == other.name and this->age == other.age;
	}

};

class customerHash {

public:

	size_t operator()(const customer& c) const {
		hash<string> stringHash;
		hash<int> integerHash;
		return stringHash(c.name) ^ integerHash(c.age);
	}

};

int main() {

	unordered_map<customer, double, customerHash> ratingMap;

	ratingMap[customer("Shiv", 20)] = 4.7;
	ratingMap[customer("Harsh", 19)] = 3.9;
	ratingMap[customer("Abhishek", 29)] = 3.2;

	for (pair<customer, double> p : ratingMap) {
		customer c = p.first;
		double r = p.second;
		cout << c.name << " " << c.age << " " << r << endl;
	}

	cout << endl;

	ratingMap[customer("Shiv", 20)] = 4.2;

	for (pair<customer, double> p : ratingMap) {
		customer c = p.first;
		double r = p.second;
		cout << c.name << " " << c.age << " " << r << endl;
	}

	return 0;
}