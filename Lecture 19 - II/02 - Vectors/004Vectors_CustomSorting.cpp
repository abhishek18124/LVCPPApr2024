#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool comparator(int a, int b) {

	if (a > b) {

		// we want a to be ordered before b since we are sorting in decreasing order

		return true;

	}

	return false;

}

class Comparator {

public:

	// return true if you want a to be ordered before b otherwise return false

	bool operator()(int a, int b) {

		if (a > b) {

			// we want a to be ordered before b since we are sorting in decreasing order

			return true;

		}

		return false;

	}

};

int main() {

	// 1. creating a vector using initialiser list

	vector<int> v = {1, 0, 2, 4, 3};

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 2. sorting a vector in the decreasing order

	// sort(v.rbegin(), v.rend());

	sort(v.begin(), v.end(), comparator);

	// greater<int> obj;

	// sort(v.begin(), v.end(), obj);

	// sort(v.begin(), v.end(), greater<int>());

	// Comparator funcObj;

	// sort(v.begin(), v.end(), funcObj); // funcObj(a, b) // funcObj.operator()(a, b)

	sort(v.begin(), v.end(), Comparator()); // we are passing an anonoymous object of the Comparator class as the third argument

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}