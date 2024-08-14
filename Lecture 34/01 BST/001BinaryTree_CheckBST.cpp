/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

int findMinimum(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root->val;

}

int findMaximum(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root->val;

}

// t(n) = 2t(n/2) + logn
// t(0) = c
// time : O(nlogn)

// t(n) = t(n-1) + n
// t(0) = c
// time : O(n^2)

bool helper(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	// 1. recursively check if the leftSubtree is a BST

	bool leftIsBST = helper(root->left);

	// 2. recursively check if the rightSubtree is a BST

	bool rightIsBST = helper(root->right);

	// 3. check if the BST prop. works at the root node

	bool rootIsBST = root->val > findMaximum(root->left) and root->val < findMinimum(root->right) ? true : false;

	return leftIsBST and rightIsBST and rootIsBST;

}

class triple {

public:

	bool isBST;
	int minVal;
	int maxVal;

};

// time : O(n)

triple helperOptimised(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {
		t.isBST = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;
		return t;
	}

	// recursive case

	triple left = helperOptimised(root->left);
	triple right = helperOptimised(root->right);

	bool rootIsBST = root->val > left.maxVal and root->val < right.minVal ? true : false;

	t.isBST = left.isBST and right.isBST and rootIsBST;
	t.minVal = min(left.minVal, min(right.minVal, root->val));
	t.maxVal = max(left.maxVal, max(right.maxVal, root->val));

	return t;

}

bool helperRange(TreeNode* root, long long lb, long long ub) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	return root->val > lb and root->val < ub and
	       helperRange(root->left, lb, root->val) and
	       helperRange(root->right, root->val, ub);

}

bool isValidBST(TreeNode* root) {

	// return helper(root);

	// triple t = helperOptimised(root);
	// return t.isBST;

	long long lb = (long long)INT_MIN - 1; // LLONG_MIN
	long long ub = (long long)INT_MAX + 1; // LLONG_MAX

	return helperRange(root, lb, ub);

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	isValidBST(root) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}