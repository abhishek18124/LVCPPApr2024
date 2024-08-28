#include<iostream>
#include<unordered_map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	unordered_map<char, node*> childMap;
	int freq;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0;
	}

};

class trie {
	node* root;
	int n; // to store the size of trie

public :

	trie() {
		root = new node('\0');
		n = 0;
	}

	// time : O(len(str))

	void insert(string str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				node* n = new node(ch);
				cur->childMap[ch] = n;
			}
			cur = cur->childMap[ch];
			cur->freq++;
		}
		cur->terminal = true;
		n++;
	}

	// time : O(len(str))

	string longestCommonPrefix(string str) {
		node* cur = root;
		string ans = "";

		for (char ch : str) {
			cur = cur->childMap[ch];
			if (cur->freq != n) break;
			ans += ch;
		}

		return ans;
	}

};


int main() {

	string words[] = {"flow", "floor", "fly"};

	// time : O(nm) to build the trie
	// space: O(nm)

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	cout << t.longestCommonPrefix(words[0]) << endl; // O(m) where m is length words[0]

	return 0;
}