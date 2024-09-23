/*

Snake and Ladders Game

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>
#include<algorithm>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {
		// insert a directed edge between vertex 'u' and 'v'
		neighbourMap[u].push_back(v);
	}

	void print() {
		for (pair<T, list<T>> vertex : neighbourMap) {
			T vertexLabel = vertex.first;
			list<T> neighbourList = vertex.second;
			cout << vertexLabel << " : ";
			for (T neighbour : neighbourList) {
				cout << neighbour << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int bfs(T s, T d) {

		map<T, int> distMap; // to store the mapping between vertices &
		// their shortest dist from the src vertex
		distMap[s] = 0;

		map<T, T> parentMap;
		parentMap[s] = s;

		unordered_set<T> visited; // to keep track of visited vertices
		queue<T> q; // to keep track of visited & un-explored vertices

		// mark 's' as visited
		visited.insert(s);
		q.push(s);

		while (!q.empty()) {
			T front = q.front();
			q.pop();

			// explore 'front'

			list<T> ngbList = neighbourMap[front];
			for (T ngb : ngbList) {
				if (visited.find(ngb) == visited.end()) {
					// ngb is not yet visited
					visited.insert(ngb);
					q.push(ngb);
					distMap[ngb] = distMap[front] + 1;
					parentMap[ngb] = front;
				}
			}

		}

		vector<T> path;

		T temp = d;

		while (parentMap[temp] != temp) {
			path.push_back(temp);
			temp = parentMap[temp];
		}

		path.push_back(temp);

		reverse(path.begin(), path.end());

		for (T node : path) {
			cout << node << " ";
		}

		cout << endl;

		return distMap[d];

	}

};

int minDiceThrows(int n,
                  vector<pair<int, int>> snakes,
                  vector<pair<int, int>> ladders) {

	vector<int> wgtMap(n + 1, 0); // 0th index is not used since we don't have cell 1

	for (pair<int, int> ladderPos : ladders) {
		int startPos = ladderPos.first;
		int endPos = ladderPos.second;
		wgtMap[startPos] = endPos - startPos;
	}

	for (pair<int, int> snakePos : snakes) {
		int startPos = snakePos.first;
		int endPos = snakePos.second;
		wgtMap[startPos] = endPos - startPos;
	}

	graph<int> g;

	for (int u = 1; u <= n - 1; u++) {

		if (wgtMap[u] != 0) {
			// at cell u, we have a snake or ladder so we won't roll die on this cell
			continue;
		}

		for (int d = 1; d <= 6; d++) {
			int v = u + d;
			if (v <= n) {
				v = v + wgtMap[v];
				g.addEdge(u, v);
			}
		}
	}

	return g.bfs(1, n);

}

int main() {

	int n = 36;

	vector<pair<int, int>> snakes  = {
		{17, 4},
		{20, 6},
		{24, 16},
		{32, 30},
		{34, 12}
	};

	vector<pair<int, int>> ladders = {
		{2, 15},
		{5, 7},
		{9, 27},
		{18, 29},
		{25, 35}
	};

	cout << minDiceThrows(n, snakes, ladders) << endl;

	return 0;
}