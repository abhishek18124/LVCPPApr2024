#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cin >> n;

	int ans = 0; // to store the unique number

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		ans = ans ^ num;
	}

	cout << ans << endl;

	return 0;
}