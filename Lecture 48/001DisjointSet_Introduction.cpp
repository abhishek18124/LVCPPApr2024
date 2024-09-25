/*

	Implementation of the disjoint set union data structure.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

template <typename T>
class disjointSet {

	unordered_map<T, T> parentMap; // to store a mapping b/w vertices & their parents

public :

	// time : O(1)
	void createSet(T x) {
		parentMap[x] = x;
	}

	// time : O(depth(x)) ~ O(hgt of the rooted tree corresponding to the set in which x is present)
	T findSet(T x) {

		// base case

		if (parentMap[x] == x) {
			return x;
		}

		// recursive case
		return findSet(parentMap[x]);

	}

	void unionSet(T x, T y) {

		T lx = findSet(x);
		T ly = findSet(y);
		if (lx != ly) {
			// perform the union b/w sets in which x and y are present
			parentMap[lx] = ly; // parentMap[ly] = lx;
		}

	}

};

int main() {

	disjointSet<int> ds;

	ds.createSet(1);
	ds.createSet(2);
	ds.createSet(3);
	ds.createSet(4);

	ds.unionSet(2, 3);

	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;

	ds.unionSet(1, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(4) << endl;

	ds.unionSet(3, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl;

	return 0;
}