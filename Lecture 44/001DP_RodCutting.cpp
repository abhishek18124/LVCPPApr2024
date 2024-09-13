/*



Given a rod of length 'n' along with prices of its pieces of different lengths, design an algorithm to
compute the maximum profit we can make by cutting the rod and a selling its pieces.

Example :

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [1,  5,  8,  9,  10, 17, 17, 20]
	Output : 22

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [3,  5,  8,  9, 10, 17, 17, 20]
	Output : 24


*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(int n, const vector<int>& p) {

	// base case

	if (n == 0) {

		// f(0) = find the max. profit given a rod of length 0

		return 0;

	}

	// recursive case

	// f(n) = find the max. profit given a rod of length n

	// todo ...

}

int main() {

	vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = p.size();

	cout << f(n, p) << endl;

	return 0;
}