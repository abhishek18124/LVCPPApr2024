/*

    Given k sorted arrays, merge them and print the sorted output.

    k = 3
    Input : {
                {1, 3, 5, 7},
                {2, 4, 6, 8},
                {0, 9, 10, 11}
            }

    Output: 0 1 2 3 4 5 6 7 8 9 10 11

*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {

    vector<vector<int>> inp = {
        {1, 3, 7, 10},
        {2, 4, 5, 11},
        {0, 6, 8, 9}
    };

    int k = inp.size(); // k=3

    // triple => vector<int> of size 3 [val, row, col]

    // priority_queue<T, vector<T>, greater<T>> minHeap;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

    // when you create a minHeap of vector<int> then the 1st value of vector i.e. value at the 0th index is used for building minHeap

    for (int i = 0; i < k; i++) {
        minHeap.push({inp[i][0], i, 0});
    }

    vector<int> out;

    while (!minHeap.empty()) {

        vector<int> minTriple = minHeap.top(); // [5, 1, 2]
        minHeap.pop();

        int val = minTriple[0]; // 5
        int row = minTriple[1]; // 1
        int col = minTriple[2]; // 2

        out.push_back(val);

        if (col + 1 < inp[row].size()) { // 2 + 1 < inp[1].size() // 3 < 4 ?

            minHeap.push({inp[row][col + 1], row, col + 1}); // inp[1][3], 1, 3 => [11, 1, 3]

        }

    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
    }

    cout << endl;

    return 0;
}