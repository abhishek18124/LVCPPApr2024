#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nearestSmallerToLeft(int A[], int n) {

	stack<int> s; // monotonic stack // <index>
	vector<int> ans;

	for (int i = 0; i < n; i++) {

		// find the index of nearest smaller element to the left of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any nearest smaller element to its left
			ans.push_back(-1);
		} else {
			ans.push_back(s.top());
		}

		s.push(i);

	}

	return ans;

}

vector<int> nearestSmallerToRight(int A[], int n) {

	stack<int> s; // monotonic stack // <index>
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		// find the index of nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any nearest smaller element to its right
			ans.push_back(n);
		} else {
			ans.push_back(s.top());
		}

		s.push(i);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

// time : O(n)
// space: O(n)

int main() {

	int h[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(h) / sizeof(int);

	vector<int> nsl = nearestSmallerToLeft(h, n); // n
	vector<int> nsr = nearestSmallerToRight(h, n); // n

	int maxSoFar = 0;

	for (int i = 0; i < n; i++) { // n

		int bestWidth = (nsr[i] - nsl[i]) - 1;
		int bestArea = h[i] * bestWidth;

		cout << bestWidth << " * " << h[i] << " = " << bestArea << endl;

		maxSoFar = max(maxSoFar, bestArea);

	}

	cout << maxSoFar << endl;

	return 0;
}