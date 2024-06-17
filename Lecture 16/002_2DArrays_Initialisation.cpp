#include<iostream>

using namespace std;

int main() {

    int arr[3][4] = {
        {10, 15, 20, 25},
        {30, 35, 40, 45},
        {50, 55, 60, 65}
    };

    int m = 3;
    int n = 4;

    // iterate over the m rows from 0th row to the m-1th row

    for (int i = 0; i <= m - 1; i++) {

        // print the ith row

        // iterate over the n cols from 0th col to the n-1th col

        for (int j = 0; j <= n - 1; j++) {

            cout << arr[i][j] << " ";

        }

        cout << endl;

    }

    cout << endl;

    return 0;
}