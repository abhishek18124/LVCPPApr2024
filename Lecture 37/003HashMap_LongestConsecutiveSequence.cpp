/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

	// time : O(n)
	// space: O(n) due to startMap

	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> startMap;

		for (int i = 0; i < nums.size(); i++) { // n steps and each step on avg. O(1) ~ linear

			// check if nums[i] can be starting point of a sequence of consecutive elements

			if (startMap.find(nums[i] - 1) == startMap.end()) {

				startMap[nums[i]] = true;

			} else {

				startMap[nums[i]] = false;

			}

			if (startMap.find(nums[i] + 1) != startMap.end()) {

				startMap[nums[i] + 1] = false;

			}

		}

		for (pair<int, bool> p : startMap) {
			int el = p.first;
			bool canStart = p.second;
			cout << el << " : " << canStart << endl;
		}

		int maxSoFar = 0; // to track the length of the longest sequence of consecutive elements

		for (pair<int, bool> p : startMap) { // linear

			int el = p.first;
			bool canStart = p.second;

			if (canStart) {

				// find the length of the sequence of consecutive elements that start at el

				int cnt = 0;

				while (startMap.find(el) != startMap.end()) {
					cnt++;
					el++;
				}

				maxSoFar = max(maxSoFar, cnt);

			}

		}

		return maxSoFar;

	}
};

int main() {

	Solution s;

	vector<int> nums = {2, 4, 3, 7, 1, 8, 9, 16, 15, 13, 12, 10, 14};

	cout << s.longestConsecutive(nums) << endl;

}
