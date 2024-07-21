#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int t, const vector<int>& c, vector<int>& perm, vector<vector<int>>& allPerm) {

	// base case

	if (t == 0) {

		allPerm.push_back(perm);
		return;

	}

	// recursion case

	// generate permutations of 'c' that sums up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	for (int j = 0; j < c.size(); j++) {

		if (c[j] <= t) {

			perm.push_back(c[j]);
			t = t - c[j];
			generatePermutations(t, c, perm, allPerm);
			t = t + c[j]; // backtracking
			perm.pop_back(); // backtracking

		}

	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<vector<int>> allPerm;
	vector<int> perm; // to track the permutation that sums up to 't'

	generatePermutations(t, c, perm, allPerm);

	for (vector<int> p : allPerm) {

		for (int x : p) {
			cout << x << " ";
		}

		cout << endl;

	}

	return 0;
}