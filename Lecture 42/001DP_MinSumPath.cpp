/*

Given a m x n grid filled with non-negative numbers, find a path from (0, 0) to (m-1, n-1),
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example :
	Input: grid = [[1,3,1],
	               [1,5,1],
	               [4,2,1]]

	Output: 7
	Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Constraints :
	1 <= m, n <= 200
	0 <= grid[i][j] <= 100

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(const vector<vector<int>>& grid, int m, int n, int i, int j) {

	// base case

	if (i == m - 1 and j == n - 1) {

		// f(m-1, n-1) = find the minimum sum path from (m-1, n-1) to (m-1, n-1)

		return grid[i][j];
	}

	// recursive cases

	// f(i, j) = find the minimum sum path from (i, j) to (m-1, n-1)

	if (i == m - 1) {
		return grid[i][j] + f(grid, m, n, i, j + 1);
	}

	if (j == n - 1) {
		return grid[i][j] + f(grid, m, n, i + 1, j);
	}

	int X = f(grid, m, n, i, j + 1);
	int Y = f(grid, m, n, i + 1, j);

	return grid[i][j] + min(X, Y);
}

int main() {

	vector<vector<int>> grid = {
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}
	};

	int m = grid.size();
	int n = grid[0].size();

	cout << f(grid, m, n, 0, 0) << endl;

	return 0;
}