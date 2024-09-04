#include<iostream>
#include<map>

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

// recursive implementation

int f(TreeNode* root) {

    // base case

    if (root == NULL) {
        return 0;
    }

    // recursive case

    // f(root) = find the max. amount of money that can be robbed from subtree rooted at root

    // decide for the root node

    // option 1 : don't rob the root node

    int donotRobRootOption = f(root->left) + f(root->right);

    // option 2 : rob the root node

    int robRootOption = root->val;

    if (root->left != NULL) {
        robRootOption += f(root->left->left) + f(root->left->right);
    }

    if (root->right != NULL) {
        robRootOption += f(root->right->left) + f(root->right->right);
    }

    return max(donotRobRootOption, robRootOption);

}

// top-down implementation

// time : worst case O(n.logn) with a map;
//      : on avg. O(n) with a unordered_map but O(n^2) in the worst case
// space: h (can be n in the worst case if tree is skewed) due to fn call stack + n due to map ~ O(n)

int fTopDown(TreeNode* root, map<TreeNode*, int>& dp) {

    // lookup

    if (dp.find(root) != dp.end()) { // every op on a map takes O(logn)

        // you've already solve f(root)
        return dp[root];

    }

    // base case

    if (root == NULL) {
        return dp[root] = 0;
    }

    // recursive case

    // f(root) = find the max. amount of money that can be robbed from subtree rooted at root

    // decide for the root node

    // option 1 : don't rob the root node

    int donotRobRootOption = fTopDown(root->left, dp) + fTopDown(root->right, dp);

    // option 2 : rob the root node

    int robRootOption = root->val;

    if (root->left != NULL) {
        robRootOption += fTopDown(root->left->left, dp) + fTopDown(root->left->right, dp);
    }

    if (root->right != NULL) {
        robRootOption += fTopDown(root->right->left, dp) + fTopDown(root->right->right, dp);
    }

    return dp[root] = max(donotRobRootOption, robRootOption);

}

int rob(TreeNode* root) {

    // return f(root);

    map<TreeNode*, int> dp;

    return fTopDown(root, dp);

}

int main() {

    // TreeNode* root = new TreeNode(3);

    // root->left = new TreeNode(2);
    // root->left->right = new TreeNode(3);

    // root->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);

    // cout << rob(root) << endl;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(5);
    root->right->right = new TreeNode(1);

    cout << rob(root) << endl;

    return 0;
}