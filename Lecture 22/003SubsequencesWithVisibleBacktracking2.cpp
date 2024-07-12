/*

Given a string of length n, generate all of its subsequences.

A subsequence of a given string (sequence) is a string (sequence) that is generated by
removing zero or more characters from the given string (sequence) without changing its
order.

Example

	Input : inp[] = "abc"
	Output: ["", "c", "b", "bc", "a", "ac", "ab", "abc"]

Constraints

  1 < n < 10

*/

#include<iostream>

using namespace std;

void f(char inp[], string& out, int i) {

	// base case

	if (inp[i] == '\0') { // i == n
		cout << out << endl;
		return;
	}

	// recursive case

	// make a decision for inp[i]

	// option 1 - include inp[i] in out[]

	out.push_back(inp[i]);
	f(inp, out, i + 1);
	out.pop_back(); // backtracking

	// option 2 - exclude inp[i] from out[]

	f(inp, out, i + 1);

}

int main() {

	char inp[] = "abc";
	string out;

	f(inp, out, 0);

	return 0;
}
