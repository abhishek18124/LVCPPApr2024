#include<iostream>
#include<vector>

using namespace std;

void f(int X[], int n, int t, int i, vector<int>& ans) {

	// base case

	if (i == n) {

		return;

	}

	// recursive case

	if (X[i] == t) {

		ans.push_back(i);

	}

	f(X, n, t, i + 1, ans);

}

int main() {

	int X[] = {10, 20, 30, 20, 30};
	int n = sizeof(X) / sizeof(int);
	int t = 200;

	vector<int> ans;

	f(X, n, t, 0, ans);

	if (ans.empty()) { // ans.size() == 0

		cout << -1 << endl;

	} else {

		for (int idx : ans) {
			cout << idx << " ";
		}

		cout << endl;

	}

	return 0;
}