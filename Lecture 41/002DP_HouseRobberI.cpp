#include<iostream>
#include<vector>

using namespace std;

// recursive implementation

int f(const vector<int>& nums, int n, int i) {

    // base case

    // todo ..

    // recursive case

    // f(i) = find the max. amount of money that can be robbed from houses[i...n-1]

    // todo ...

}

int rob(vector<int>& nums) {

    int n = nums.size();

    return f(nums, n, 0);

}

int main() {

    vector<int> nums = {100, 50, 400, 200, 100};

    cout << rob(nums) << endl;

    return 0;

}