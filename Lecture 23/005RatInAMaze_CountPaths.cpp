/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> count the number of paths that exist between src and dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output : 3

*/

#include<iostream>

using namespace std;

int f(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) {
		return 0;
	}

	if (maze[i][j] == 'X') {
		return 0;
	}

	if (i == m - 1 and j == n - 1) {
		return 1;
	}

	// recursive case

	// find the no. of paths to go from (i, j)th cell to (m-1, n-1)th cell ?

	// decide the next step

	// option 1 : move right => ask your friend to find the  no. of paths to go from (i, j+1)th cell to the (m-1, n-1)th cell

	int x = f(maze, m, n, i, j + 1);

	// option 2 : move down => ask your friend to find the no. of paths to go from (i+1, j)th cell to the (m-1, n-1)th cell

	int y = f(maze, m, n, i + 1, j);

	return x + y;

}

int main() {

	char maze[][10] = {
		"0000",
		"0XX0",
		"0X0X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	cout << f(maze, m, n, 0, 0) << endl;

	return 0;
}