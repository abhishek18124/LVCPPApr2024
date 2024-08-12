#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

class Triple {
public :

	int numCameras;
	bool isCovered; // isMonitored
	bool hasCamera;

};

// time : O(n)
// space: O(h) where h is the height of recursion tree due to function call-stack

Triple helper(TreeNode* root) {

	Triple t;

	// base case

	if (root == NULL) {

		t.numCameras = 0;
		t.hasCamera = false;
		t.isCovered = true;

		return t;

	}

	// recursive case

	Triple left = helper(root->left);
	Triple right = helper(root->right);

	// make a decision for the root node

	if (!left.isCovered || !right.isCovered) {

		// install a camera at the root node

		t.numCameras = left.numCameras + right.numCameras + 1;
		t.hasCamera = true;
		t.isCovered = true;

		return t;

	}

	// don't install camera at the root node

	t.numCameras = left.numCameras + right.numCameras;
	t.hasCamera = false;
	t.isCovered = left.hasCamera || right.hasCamera ? true : false;

	return t;

}

int minCameraCover(TreeNode* root) {

	Triple t = helper(root);
	if (t.isCovered == false) {
		// install camera at the root node
		return t.numCameras + 1;
	}
	return t.numCameras;

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(0);

	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);

	cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	root = new TreeNode(0);

	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);

	root->right = new TreeNode(0);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(0);

	cout << minCameraCover(root) << endl;

	return 0;
}