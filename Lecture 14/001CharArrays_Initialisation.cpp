#include<iostream>

using namespace std;

int main() {

	char str1[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << str1 << endl;

	char str2[6] = {'u', 'v', 'w', 'x', 'y', '\0'};
	cout << str2 << endl;

	char str3[] = "hello"; // '\0' is added automatically
	cout << str3 << endl;
	cout << "sizeof(str3) = " << sizeof(str3) << endl;

	return 0;

}