/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class maxHeap {

	vector<int> v;

	void heapify(int i) { // [HW] try to impl. heapify iteratively

		// fix the heap propery at the ith index

		int maxIdx = i;

		int leftIdx = 2 * i + 1;
		if (leftIdx < v.size() and v[leftIdx] > v[maxIdx]) {
			maxIdx = leftIdx;
		}

		int rightIdx = 2 * i + 2;
		if (rightIdx < v.size() and v[rightIdx] > v[maxIdx]) {
			maxIdx = rightIdx;
		}

		// base case : if maxIdx is equal to i that means heap property is not violated at the ith index so we can stop making recursive calls

		if (maxIdx != i) {
			swap(v[i], v[maxIdx]);
			heapify(maxIdx);
		}

	}

public:

	// time : O(logn)

	void push(int val) {

		v.push_back(val);

		int childIdx = v.size() - 1;
		int parentIdx = childIdx % 2 == 1 ? childIdx / 2 : childIdx / 2 - 1;

		while (childIdx != 0 and v[childIdx] > v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = childIdx % 2 == 1 ? childIdx / 2 : childIdx / 2 - 1;
		}

	}

	// time : O(logn)

	void pop() {

		swap(v[0], v[v.size() - 1]); // const
		v.pop_back(); // const
		heapify(0); // logn

	}

	// time : O(1)

	int top() {
		return v[0];
	}

	// time : O(1)

	int size() {
		return v.size();
	}

	// time : O(1)
	bool empty() {
		return v.empty();
	}

};

int main() {

	maxHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}



