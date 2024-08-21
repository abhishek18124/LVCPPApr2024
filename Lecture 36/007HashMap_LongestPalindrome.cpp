#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// time : O(n)
// space: O(n) if all characters are unique (maximum size = 52 (a-z, A-Z))

int longestPalindromeLength(const string& s) {

	unordered_set<char> us;
	int cnt = 0;

	for (char ch : s) {
		if (us.find(ch) != us.end()) {
			// you've seen ch previously
			cnt += 2;
			us.erase(ch);
		} else {
			// track ch, it may combine with same character in future
			us.insert(ch);
		}
	}

	if (us.size() > 0) {
		// you can build a odd-len palindromie by using any one of the char. present in the us in the middle
		cnt++;
	}

	return cnt;

}

int main() {

	string str = "ccccddbbbbb";

	cout << longestPalindromeLength(str) << endl;

	return 0;
}