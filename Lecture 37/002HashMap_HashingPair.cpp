#include<iostream>
#include<unordered_map>

using namespace std;

class pairHash {

public:

	size_t operator()(const pair<string, int>& p) const {

		// hash<string> stringHash;
		// hash<int> integerHash;
		// return stringHash(p.first) ^ integerHash(p.second);

		return hash<string>()(p.first) ^ hash<int>()(p.second);

	}

};

int main() {

	unordered_map<pair<string, int>, double, pairHash> ratingMap;

	ratingMap[ {"Shiv", 20}] = 4.7;
	ratingMap[ {"Harsh", 19}] = 3.9;
	ratingMap[ {"Abhishek", 29}] = 3.2;

	for (pair<pair<string, int>, double> p : ratingMap) {
		pair<string, int> c = p.first;
		double r = p.second;
		cout << c.first << " " << c.second << " " << r << endl;
	}

	cout << endl;

	ratingMap[ {"Shiv", 20}] = 4.2;

	for (pair<pair<string, int>, double> p : ratingMap) {
		pair<string, int> c = p.first;
		double r = p.second;
		cout << c.first << " " << c.second << " " << r << endl;
	}


	return 0;
}