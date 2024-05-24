#include<iostream>

using namespace std;

int main() {

	int arr[] = {50, 40, 20, 30, 10};
	int n = sizeof(arr) / sizeof(int);

	// todo ...
	
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	
	return 0;
}