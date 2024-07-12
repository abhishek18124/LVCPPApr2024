/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (i == n) {
		cout << inp << endl;
		return;
	}

	// recursive case

	// decide for ith position

	// swap(inp[i], inp[i])
	// swap(inp[i], inp[i+1])
	// swap(inp[i], inp[i+2])
	// ...
	// swap(inp[i], inp[n-1])

	// swap(inp[i], inp[j]) i <= j <= n-1

	for (int j = i; j <= n - 1; j++) {

		swap(inp[i], inp[j]);
		f(inp, n, i + 1);
		swap(inp[i], inp[j]); // backtracking

	}

}

int main() {

	char inp[] = "abc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}
