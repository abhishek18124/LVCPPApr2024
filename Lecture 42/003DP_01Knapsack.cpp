/*

Example :
	Input : N = 5, W = 4
			wt[] = {1, 2, 3, 2, 2}
			pr[] = {8, 4, 1, 5, 3}
	Output: 13

*/


#include<iostream>
#include<vector>

using namespace std;

int f(vector<int> wt, vector<int> pr, int N, int i, int w) {

	// base case

	// todo ...

	// recursive case

	// f(i, w) = find the max. profit from items[i...N-1] such that knapsack capacity is w

	// todo ...

}

int main() {

	int N = 5;
	int W = 4;

	vector<int> wt = {1, 2, 3, 2, 2};
	vector<int> pr = {8, 4, 1, 5, 3};

	cout << f(wt, pr, N, 0, W) << endl;

	return 0;
}