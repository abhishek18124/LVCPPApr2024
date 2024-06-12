#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool lengthCompare(string a, string b) {

	int len_a = a.size();
	int len_b = b.size();

	if (len_a < len_b) {

		// I want a to be ordered before b since we are sorting length-wise in the inc. order
		return true;

	}

	return false;

}

int main() {

	string arr[] = {"xyz", "ab", "cdef"};

	// sort(arr, arr + 3);
	sort(arr, arr + 3, lengthCompare);

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}