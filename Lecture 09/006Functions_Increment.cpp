#include<iostream>

using namespace std;

void inc(int a) {

	cout << "before ++ a = " << a << endl;

	a++;

	cout << "after ++ a = " << a << endl;

}

int main() {

	int a = 0;

	cout << "before inc() a = " << a << endl;

	inc(a);

	cout << "after inc() a = " << a << endl;

	return 0;
}