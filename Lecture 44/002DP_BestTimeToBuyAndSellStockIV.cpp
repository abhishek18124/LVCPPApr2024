// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {

public:

    int f(const vector<int>& prices, int N, int i, int k) {

        // base case

        if (i == N || k == 0) {
            return 0;
        }

        // recursive case

        // f(i, k) = find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. do not buy the stock on the ith day

        int donotBuyOption = f(prices, N, i + 1, k);

        // 2. buy the stock on the ith day

        // decide when to sell the stock bought on the ith day

        int maxBuyOptionSoFar = 0;

        for (int j = i + 1; j <= N - 1; j++ ) {

            maxBuyOptionSoFar = max(maxBuyOptionSoFar,
                                    (prices[j] - prices[i]) + f(prices, N, j + 1, k - 1));

        }

        return max(donotBuyOption, maxBuyOptionSoFar);

    }


    int fTopDown(const vector<int>& prices, int N, int i, int k, vector<vector<int>>& dp) {

        // lookup

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        // base case

        if (i == N || k == 0) {
            return dp[i][k] = 0;
        }

        // recursive case

        // f(i, k) = find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. do not buy the stock on the ith day

        int donotBuyOption = fTopDown(prices, N, i + 1, k, dp);

        // 2. buy the stock on the ith day

        // decide when to sell the stock bought on the ith day

        int maxBuyOptionSoFar = 0;

        for (int j = i + 1; j <= N - 1; j++ ) {

            maxBuyOptionSoFar = max(maxBuyOptionSoFar,
                                    (prices[j] - prices[i]) + fTopDown(prices, N, j + 1, k - 1, dp));

        }

        return dp[i][k] = max(donotBuyOption, maxBuyOptionSoFar);

    }

    int fBottomUp(const vector<int>& prices, int N, int K) {

        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0)); // Nth row and 0th col (base case)

        for (int i = N - 1; i >= 0; i--) {
            for (int k = 1; k <= K; k++) {
                // dp[i][k] = f(i, k) = find the maximum profit you can make by completing <=k transactions starting from the ith day

                // make a decision for the ith day

                // 1. do not buy the stock on the ith day

                int donotBuyOption = dp[i + 1][k];

                // 2. buy the stock on the ith day

                // decide when to sell the stock bought on the ith day

                int maxBuyOptionSoFar = 0;

                for (int j = i + 1; j <= N - 1; j++ ) {

                    maxBuyOptionSoFar = max(maxBuyOptionSoFar,
                                            (prices[j] - prices[i]) + dp[j + 1][k - 1]);

                }

                dp[i][k] = max(donotBuyOption, maxBuyOptionSoFar);
            }
        }

        return dp[0][K]; // at the 0,Kth index we store f(0, K)

    }


    int maxProfit(int K, vector<int>& prices) {

        int N = prices.size();

        // return f(prices, N, 0, K);

        // vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));

        // return fTopDown(prices, N, 0, K, dp);

        return fBottomUp(prices, N, K);

    }
};