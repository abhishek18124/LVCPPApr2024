#include<iostream>
#include<vector>

using namespace std;

int peakIndexInMountainArray(const vector<int>& arr) {

	int n = arr.size();

	int s = 0;
	int e = n - 1;

	while (s < e) {

		int m1 = s + (e - s) / 3;
		int m2 = e - (e - s) / 3;

		if (arr[m1] > arr[m2]) {

			e = m2 - 1;

		} else {

			s = m1 + 1;

		}

	}

	return arr[s]; // arr[e] // here s is equal to e

}

int main() {

	vector<int> arr = {1, 2, 3, 4, 3, 2, 1};
	cout << peakIndexInMountainArray(arr) << endl;

	return 0;
}