#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int arr[] = { -2, 0, -1, 2, -3, 1, 3, 2, 4};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i = 0;     // to store the start of the window
	int j = 0;     // to store the end of the window

	// time : O(n)
	// space: O(k) due to queue when a window has only negative nos.

	queue<int>  q; // to store negative numbers in a window
	vector<int> v; // to store first negative number for each k-sized window

	// find the first negative number in the 1st window

	while (j < k) { // k
		if (arr[j] < 0) {
			q.push(arr[j]);
		}
		j++;
	}

	q.empty() ? v.push_back(0) : v.push_back(q.front());

	// find the first negative number in the remaining windows

	while (j < n) { // n-k

		// slide the window
		if (arr[i] < 0) q.pop();
		i++;
		if (arr[j] < 0) q.push(arr[j]);

		q.empty() ? v.push_back(0) : v.push_back(q.front());

		j++;

	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}

