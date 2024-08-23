/*
	https://leetcode.com/problems/find-duplicate-subtrees/
*/

class Solution {
public:

	string dfs(TreeNode* root, unordered_map<string, TreeNode*>& treeMap, unordered_set<TreeNode*>& ans) {

		// base case

		if (root == NULL) {
			return "x";
		}

		// recursive case

		string leftRepr = dfs(root->left, treeMap, ans);
		string rightRepr = dfs(root->right, treeMap, ans);
		string treeRepr = to_string(root->val) + "-" + leftRepr + "-" + rightRepr;

		if (treeMap.find(treeRepr) != treeMap.end()) {

			// you've seen treeRepr previously
			ans.insert(treeMap[treeRepr]);

		} else {

			// you are seeing treeRepr for the 1st time
			treeMap[treeRepr] = root;

		}

		return treeRepr;

	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

		unordered_map<string, TreeNode*> treeMap; // subtreeRepr -> address
		unordered_set<TreeNode*> ans;

		dfs(root, treeMap, ans);

		vector<TreeNode*> v(ans.begin(), ans.end());
		return v;

	}
};