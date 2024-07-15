#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int t, vector<int> c, vector<int>& perm) {

	// base case

	// todo ...

	// recursion case

	// generate permutations of 'c' that sums up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	// todo ...

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> perm; // to track the permutation that sums up to 't'

	generatePermutations(t, c, perm);

	return 0;
}