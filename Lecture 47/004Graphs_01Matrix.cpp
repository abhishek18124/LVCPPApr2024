// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

// 1. brute-force approach - time : O(m^2.n^2)

vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// find the manhattan dist of all the cells from the (i, j)th cell
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < n; jj++) {
						// find the manhattan dist b/w the (i, j)th and (ii, jj)th cell
						dist[ii][jj] = min(dist[ii][jj], abs(ii - i) + abs(jj - j));
					}
				}
			}
		}
	}

	return dist;

}

// multi-source BFS

// time : O(mn)

vector<vector<int>> updateMatrixOptimised(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // if dist[i][j] is INT_MAX then i,jth cell is not yet visited

	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// i,jth cell corresponds to a source vertex
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}

	vector<int> dx = {0, 0, -1, 1};
	vector<int> dy = {1, -1, 0, 0};

	while (!q.empty()) {

		pair<int, int> front = q.front();
		q.pop();

		int i = front.first;
		int j = front.second;

		for (int k = 0;  k < 4; k++) {

			int nx = i + dx[k];
			int ny = j + dy[k];

			if (nx >= 0 and nx <= m - 1 and ny >= 0 and ny <= n - 1 and dist[nx][ny] == INT_MAX) {

				// nx, ny is not yet visited
				q.push({nx, ny});
				dist[nx][ny] = dist[i][j] + 1;

			}

		}

	}

	return dist;

}

int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	// vector<vector<int>> dist = updateMatrix(mat);
	vector<vector<int>> dist = updateMatrixOptimised(mat);

	for (vector<int> row : dist) {
		for (int col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	return 0;
}