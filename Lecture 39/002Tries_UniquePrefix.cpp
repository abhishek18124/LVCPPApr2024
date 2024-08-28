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

public :

	trie() {
		root = new node('\0');
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
	}

	// time : O(len(str))

	string uniquePrefix(string str) {
		string ans = "";
		node* cur = root;
		for (char ch : str) {
			cur = cur->childMap[ch];
			ans += ch;
			if (cur->freq == 1) {
				return ans;
			}
		}
		return "";
	}

};


int main() {

	string words[] = {"code", "coder", "coding", "new", "neon"};

	// total time : nm + nm ~ O(nm) better brute-force
	// total space: nm + 1 incl. root ~ O(nm)

	// time : nm

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	// time : nm where n is no. of words and m is len of each str

	for (string word : words) {
		cout << "uniquePrefix(" << word << ") = " << t.uniquePrefix(word) << endl;
	}

	return 0;
}