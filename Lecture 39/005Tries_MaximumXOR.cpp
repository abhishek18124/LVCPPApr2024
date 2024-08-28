/*

Given an array of non-negative integers of size n, find the maximum possible XOR between
any two numbers present in the array.

Example:
	Input : x[] = {25, 10, 2, 8, 5, 3}
	Output: 28
	Explaination: The maximum result is 5 ^ 25 = 28

	Input: x[] = {1, 2, 3, 4, 5, 6, 7}
	Output: 7
	Explaination: The maximum result is 1 ^ 6 = 7

*/

#include<iostream>
#include<climits>

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

	int maximumXOR(int x[], int n) {
		int maxSoFar = 0;
		for (int i = 0; i < n; i++) { // n.32 steps
			maxSoFar = max(maxSoFar, helper(x[i]));
		}
		return maxSoFar;
	}
};

int main() {

	int x[] = {2, 4, 5, 8, 10};
	int n = sizeof(x) / sizeof(int);

	// // brute-force ~ O(n^2)

	// int maxSoFar = 0;

	// for (int i = 0; i < n - 1; i++) {
	// 	for (int j = i + 1; j < n; j++) {
	// 		cout << x[i] << "^" << x[j] << " = " << (x[i]^x[j]) << endl;
	// 		maxSoFar = max(maxSoFar, x[i] ^ x[j]);
	// 	}
	// 	cout << endl;
	// }

	// cout << maxSoFar << endl;

	// total time : n.32 to build trie + n.32 to get the ans ~ O(n)
	// total time :

	trie t;

	for (int i = 0; i < n; i++) { // n.32 steps
		t.insert(x[i]);
	}

	cout << t.maximumXOR(x, n) << endl;

	return 0;
}