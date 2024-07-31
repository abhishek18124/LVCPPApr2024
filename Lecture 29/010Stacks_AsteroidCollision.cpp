#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;

	for (int ast : asteroids) {

		if (ast < 0 and !s.empty() and s.top() > 0) {

			// collions will occur

			bool flag = true; // assume ast will survive all the collisions

			while (!s.empty() and s.top() > 0) {

				if (abs(ast) > s.top()) {

					// asteroid at the top of the stack will be destroyed

					s.pop();

				} else if (abs(ast) < s.top()) {

					// ast will be destroyed

					flag = false;
					break;

				} else {

					// abs(ast) is equal to s.top()

					// both asteroid at the top of the stack and ast will be destroyed

					s.pop();
					flag = false;
					break;

				}

			}

			if (flag) {

				s.push(ast);

			}

		} else {

			// no collusion will occur for now

			s.push(ast);

		}

	}

	vector<int> finalState;

	while (!s.empty()) {
		finalState.push_back(s.top());
		s.pop();
	}

	reverse(finalState.begin(), finalState.end());

	return finalState;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> finalState = asteroidCollision(asteroids);

	for (int i = 0; i < finalState.size(); i++) {
		cout << finalState[i] << " ";
	}

	cout << endl;

	return 0;
}