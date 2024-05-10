#include<iostream>
#define PI 3.14
#define PRINT cout <<
#define NEWLINE endl
#define ll long long // we will use this in course
#define F5 for(int i=1; i<=5; i++) { cout << i << " ";}
#define F(n) for(int i=1; i<=n; i++) {cout << i << " ";}

using namespace std;

int main() {

	PRINT PI << NEWLINE; // PI is replaced by 3.14 before the compilation by the preprocessor

	PRINT 2 * PI << NEWLINE;

	PRINT "HELLO" << NEWLINE;

	ll x;

	// F5

	int n;
	cin >> n;

	F(n)

	return 0;
}