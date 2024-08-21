/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// key (string) -> value (vector<string>)

// name1 -> [p11, p12, ...]
// name2 -> [p21, p21, ...]
// ...

int main() {

	unordered_map<string, vector<string>> phoneMap;

	phoneMap["Shiv"].push_back("1234");
	phoneMap["Shiv"].push_back("5678");
	phoneMap["Shiv"].push_back("0000");

	phoneMap["Abrar"].push_back("1111");

	phoneMap["Prachi"].push_back("0123");
	phoneMap["Prachi"].push_back("3210");

	for (pair<string, vector<string>> contact : phoneMap) {
		string contactName = contact.first;
		vector<string> phoneNums = contact.second;
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}