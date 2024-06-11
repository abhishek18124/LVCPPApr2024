#include<iostream>
#include<cstring>

using namespace std;

int findLength(char str[]) {

	int cnt = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		cnt++;
	}

	return cnt;

}

int main() {

	char str[] = "coding blocks";

	cout << findLength(str) << endl;

	cout << strlen(str) << endl;

	return 0;
}