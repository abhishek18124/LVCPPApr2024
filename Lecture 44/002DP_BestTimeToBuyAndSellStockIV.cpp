// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {

public:

    int f(const vector<int>& prices, int N, int i, int k) {

        // base case

        // recursive case

        // f(i, k) = find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. do not buy the stock on the ith day

        // 2. buy the stock on the ith day

    }

    int maxProfit(int K, vector<int>& prices) {

        int N = prices.size();

        return f(prices, N, 0, K);

    }
};