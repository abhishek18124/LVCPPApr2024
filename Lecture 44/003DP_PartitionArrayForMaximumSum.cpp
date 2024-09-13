#include<iostream>
#include<vector>

using namespace std;

int f(const vector<int>& arr, int N, int k, int i, vector<int>& dp) {

	// base case

	// todo ...

	// recursive case

	// todo ...

}

int maxSumAfterPartitioning(vector<int>& arr, int K) {

	int N = arr.size();

	return f(arr, N, K, 0);
}

int main() {

	vector<int> arr = {1, 2, 3, 4, 5, 6};
	int K = 1;

	cout << maxSumAfterPartitioning(arr, K) << endl;

	return 0;
}