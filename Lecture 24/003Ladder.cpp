/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number
of ways, the person can reach the top of the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>
#include<vector>

using namespace std;

vector<int> path;

int f(int n, int k, int i) {

	// base case

	if (i == n) {

		for (int x : path) {
			cout << x << " ";
		}
		cout << endl;
		return 1;

	}

	// recursive case

	// find the no. of ways to go from ith step to the nth step

	// decide the next step

	// take a jump of size 1 => ask your friend to find the no. of ways to go from i+1th step to the nth step i.e. f(i+1)
	// take a jump of size 2 => ask your friend to find the no. of ways to go from i+2th step to the nth step i.e. f(i+2)
	// take a jump of size 3 => ask your friend to find the no. of ways to go from i+3rd step to the nth step i.e. f(i+3)
	// ...
	// take a jump of size k => ask your friend to find the no. of ways to go from i+kth step to the nth step i.e. f(i+k)

	// take a jump of size 1<=j<=k => => ask your friend to find the no. of ways to go from i+jth step to the nth step

	int cnt = 0;

	for (int j = 1; j <= k; j++) {

		// can you take a jump of size j while standing at the ith step

		if (i + j <= n) {

			// lets take a jump of size j
			path.push_back(j);
			cnt += f(n, k, i + j);
			path.pop_back(); // backtracking

		}

	}

	return cnt;


}

int main() {

	int n = 4;
	int k = 3;

	cout << f(n, k, 0) << endl;

	return 0;
}