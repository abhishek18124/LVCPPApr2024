#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int& y = x;

	y++;

	cout << x << " " << y << endl;

	return 0;
}