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


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	// base case

	if (root == NULL) {
		return NULL;
	}

	if (root == p || root == q) { // root->val == p->val || root->val == q->val

		// if root is p then you assume q to be in the subtree of p therefore lca is p hence you return root
		// if root is q then you assume p to be in the subtree of q therefore lca is q hence you return root

		return root;
	}

	// recursive case

	// find the lca(p, q)

	// 1. find the lca(p, q) in the leftSubree

	TreeNode* left = lowestCommonAncestor(root->left, p, q);

	// 2. find the lca(p, q) in the rightSubtree

	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	if (left != NULL and right != NULL) {
		return root;
	} else if (left != NULL) { // right == NULL
		return left;
	} else if (right != NULL) { // left == NULL
		return right;
	}

	return NULL; // left == NULL and right == NULL

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(3);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	root->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	return 0;
}