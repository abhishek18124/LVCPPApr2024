/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>
#include<set>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (i == n) {
		cout << inp << endl;
		return;
	}

	// recursive case

	// decide for ith position

	for (int j = i; j <= n - 1; j++) {

		// can you bring inp[j] to the ith position ?

		bool flag = true; // assume you can bring inp[j] to the ith position

		for (int k = j + 1; k < n; k++) {
			if (inp[k] == inp[j]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			swap(inp[i], inp[j]);
			f(inp, n, i + 1);
			swap(inp[i], inp[j]); // backtracking
		}

	}

}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}
