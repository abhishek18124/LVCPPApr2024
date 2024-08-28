/*

Given an array of non-negative integers, find the maximum subarray XOR.

Example:
	Input : x[] = {25, 10, 2, 8, 5, 3}
	Output:

*/

#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class node {
public:

	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1

	node() {
		this->left = NULL;
		this->right = NULL;
	}
};

class trie {

	node* root;

public:

	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (1 << i)&n;
			if (!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if (!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if (!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	int helper(int n) { // time : 32-steps

		// find the maximum possible xor involving n in just 1 xor operation using trie

		int ans = 0;
		node* cur = root;

		for (int i = 31; i >= 0; i--) {

			int ithBit = (n >> i) & 1;

			if (ithBit == 0) {
				if (cur->right != NULL) {
					// ithBit of ans can be 1
					ans = ans + (1 << i); // 1<<i is equal to 2^i
					cur = cur->right;
				} else {
					// ithBit of ans cannot be 1, you've no option but to move left
					cur = cur->left;
				}
			} else {
				// ithBit is 1
				if (cur->left != NULL) {
					// ithBit of ans can be 1
					ans = ans + (1 << i);
					cur = cur->left;
				} else {
					// ithBit of ans cannot be 1, you've no option but to move right
					cur = cur->right;
				}
			}
		}

		cout << n << "^" << (ans ^ n) << " = " << ans << endl;

		return ans;

	}

	int maximumXOR(vector<int> x, int n) {
		int maxSoFar = 0;
		for (int i = 0; i < n; i++) { // n.32 steps
			maxSoFar = max(maxSoFar, helper(x[i]));
		}
		return maxSoFar;
	}
};

int main() {

	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(arr) / sizeof(int);

	// // brute-force approach - time : O(n^3) space : O(1)

	// int maxXOR = 0; // to track the maximum subarray XOR

	// for (int i = 0; i < n; i++) {
	// 	for (int j = i; j < n; j++) {
	// 		// compute the xor of arr[i...j]
	// 		int XOR = 0;
	// 		for (int k = i; k <= j; k++) {
	// 			XOR ^= arr[k];
	// 		}
	// 		maxXOR = max(maxXOR, XOR);
	// 	}
	// }

	// cout << maxXOR << endl;

	// using cxor[] - time : n + n^2 ~ O(n^2) space : O(n) due to cxor[]

	vector<int> cxor(n + 1);
	cxor[0] = 0;

	for (int i = 1; i <= n; i++) {
		cxor[i] = cxor[i - 1] ^ arr[i - 1];
	}

	// int maxXOR = 0; // to track the maximum subarray XOR

	// for (int i = 0; i < n; i++) {
	// 	for (int j = i; j < n; j++) {
	// 		// compute the xor of arr[i...j]
	// 		int XOR = cxor[j + 1] ^ cxor[i];
	// 		maxXOR = max(maxXOR, XOR);
	// 	}
	// }

	// cout << maxXOR << endl;

	trie t;
	for (int i = 0; i <= n; i++) {
		t.insert(cxor[i]);
	}

	cout << t.maximumXOR(cxor, n + 1) << endl;

	return 0;
}