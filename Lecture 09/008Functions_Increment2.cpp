#include<iostream>

using namespace std;

void inc(int& ref) {

	ref++;

}

int main() {

	int a = 0;

	cout << "inside main(), before inc() a = " << a << endl;

	inc(a);

	cout << "inside main(), after inc() a = " << a << endl;

	return 0;
}