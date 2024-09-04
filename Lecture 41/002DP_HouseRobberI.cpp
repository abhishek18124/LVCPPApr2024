#include<iostream>
#include<vector>

using namespace std;

// recursive implementation

// time : O(2^n)
// space: O(n) due to function call stack

int f(const vector<int>& nums, int n, int i) {

    // base case

    if (i == n || i == n + 1) {
        return 0;
    }

    // recursive case

    // f(i) = find the max. amount of money that can be robbed from houses[i...n-1]

    // decide for the ith house

    // option 1 : rob the ith house

    // option 2 : don't rob the ith house

    return max(nums[i] + f(nums, n, i + 2),
               f(nums, n, i + 1));

}

// top-down implementation

// time : n+2.const ~ O(n)
// space: (n+1) due to fn call stack + (n+2) due to dp[] ~ O(n)

int fTopDown(const vector<int>& nums, int n, int i, vector<int>& dp) {

    // lookup

    if (dp[i] != -1) {

        // you've already solved f(i)
        return dp[i];

    }

    // base case

    if (i == n || i == n + 1) {
        return dp[i] = 0;
    }

    // recursive case

    // f(i) = find the max. amount of money that can be robbed from houses[i...n-1]

    // decide for the ith house

    // option 1 : rob the ith house

    // option 2 : don't rob the ith house

    return dp[i] = max(nums[i] + fTopDown(nums, n, i + 2, dp),
                       fTopDown(nums, n, i + 1, dp));

}

// time : O(n)
// space: O(n) due to dp[]

int fBottomUp(const vector<int>& nums, int n) {

    vector<int> dp(n + 2);

    dp[n + 1] = 0;
    dp[n] = 0; // at the n+1th index and nth index of dp[] we store f(n+1) and f(n) resp.

    for (int i = n - 1; i >= 0; i--) {

        // dp[i] = f(i) = find the max. amount of money that can be robbed from houses[i...n-1]

        // decide for the ith house

        // option 1 : rob the ith house

        // option 2 : don't rob the ith house

        dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);

    }

    return dp[0]; // at the 0th index of dp[] we store f(0)

}

int rob(vector<int>& nums) {

    int n = nums.size();

    // return f(nums, n, 0);

    // vector<int> dp(n + 2, -1);

    // return fTopDown(nums, n, 0, dp);

    return fBottomUp(nums, n);

}

int main() {

    vector<int> nums = {100, 50, 400, 200, 100};

    cout << rob(nums) << endl;

    return 0;

}