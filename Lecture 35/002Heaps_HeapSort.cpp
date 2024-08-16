/*

	Given an array of n integers, sort the array using heap sort algorithm.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) {

	int maxIdx = i;
	int leftIdx = 2 * i + 1;

	if (leftIdx < n and v[leftIdx] > v[maxIdx]) {
		maxIdx = leftIdx;
	}

	int rightIdx = 2 * i + 2;
	if (rightIdx < n and v[rightIdx] > v[maxIdx]) {
		maxIdx = rightIdx;
	}

	if (maxIdx != i) {
		swap(v[i], v[maxIdx]);
		heapify(v, n, maxIdx);
	}

}


int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// total time = n + nlogn ~ O(nlogn)
	// space = O(logn) due to fn call stack for heapify => can be optimised to O(1) if you impl. heapify iteratively

	// 1. transfor v[] into a maxHeap - O(n)

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	// 2. transform v[] i.e. maxHeap into a sorted v[]

	int heapsize = n;

	while (heapsize > 1) { // O(nlogn)
		swap(v[0], v[heapsize - 1]); // const
		heapsize--; // const
		heapify(v, heapsize, 0); // logn
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
