#include<iostream>

using namespace std;

// steps = n + n + 26
// space = 26 + 26

bool isAnagram(char s1[], char s2[]) {

	// 1. build a freqMap for s1[]

	int f1[26] = {0};

	for (int i = 0; s1[i] != '\0'; i++) {

		char ch = s1[i];
		int idx = ch - 'a';
		f1[idx]++;

	}

	for (int i = 0; i < 26; i++) {
		cout << f1[i] << " ";
	}

	cout << endl;

	// 2. build a freqMap for s2[]

	int f2[26] = {0};

	for (int i = 0; s2[i] != '\0'; i++) {

		f2[s2[i] - 'a']++;

	}

	for (int i = 0; i < 26; i++) {
		cout << f2[i] << " ";
	}

	cout << endl;

	// 3. compare the two freqMaps

	for (int i = 0; i < 26; i++) {

		if (f1[i] != f2[i]) {
			// s1 and s2 are not anagrams since char mapped to the ith index has different frequencies in s1 and s2
			return false;
		}

	}

	// s1 and s2 are anagrams

	return true;

}

int main() {

	char s1[] = "aabbbcc";
	char s2[] = "aaabbcc";

	isAnagram(s1, s2) ? cout << "anagram" << endl : cout << "not an anagram" << endl;

	return 0;
}