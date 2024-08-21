#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

// time : O(n)
// spacE: O(n) due to indexMap

bool doesExist(const vector<int>& v, int k) {

	unordered_map<int, int> indexMap; // <elment, index>

	for (int i = 0; i < v.size(); i++) {

		if (indexMap.find(v[i]) != indexMap.end()) {

			// you've seen v[i] previously, where ? indexMap[v[i]]

			int j = indexMap[v[i]]; // j repr. the index of v[i] when it was seen last
			if (abs(i - j) <= k) {
				return true;
			}

		}

		indexMap[v[i]] = i;

	}

	return false;

}

int main() {

	vector<int> v = {1, 2, 3, 1, 2, 3, 1, 3};
	int k = 2;

	doesExist(v, k) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}