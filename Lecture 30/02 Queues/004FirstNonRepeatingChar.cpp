#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<char> q;
	int freqMap[26] = {0};

	char ch;

	while (true) {

		cin >> ch;

		if (ch == '.') break;

		freqMap[ch - 'a']++;
		if (freqMap[ch - 'a'] == 1) {
			q.push(ch);
		}

		// use queue to know what is the 1st non-repeating char in the stream after reading ch

		while (!q.empty() and freqMap[q.front() - 'a'] > 1) {
			q.pop();
		}

		if (q.empty()) {
			// there is no non-repeating char. in the stream currently
			cout << -1 << " ";
		} else {
			cout << q.front() << " ";
		}

	}

	return 0;
}