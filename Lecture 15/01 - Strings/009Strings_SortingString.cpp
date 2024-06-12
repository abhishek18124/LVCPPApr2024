#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "axbycz";

	sort(s.begin(), s.end());

	cout << s << endl;

	sort(s.rbegin(), s.rend()); // sorts s in dec. order

	cout << s << endl;

	sort(s.begin(), s.end());

	cout << s << endl;

	sort(s.begin(), s.end(), greater<char>()); // sorts s in dec. order

	cout << s << endl;

	return 0;
}