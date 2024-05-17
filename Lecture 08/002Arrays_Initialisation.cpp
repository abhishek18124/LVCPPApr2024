#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};

	// cout << A[0] << endl;
	// cout << A[1] << endl;
	// cout << A[2] << endl;
	// cout << A[3] << endl;
	// cout << A[4] << endl;

	int n = sizeof(A) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}

	cout << endl;

	for (int i = 0; i <= n - 1; i++) {
		cout << A[i] << endl;
	}

	cout << endl;

	int B[] = {100, 200, 300, 400, 500, 600, 700};
	int m = sizeof(B) / sizeof(int);

	cout << m << endl;

	for (int i = 0; i < m; i++) {
		cout << B[i] << endl;
	}

	cout << endl;

	int C[5] = {1000, 2000, 3000};

	int o = sizeof(C) / sizeof(int);

	cout << o << endl;

	for (int i = 0; i < o; i++) {
		cout << C[i] << endl;
	}

	cout << endl;

	int D[5] = {};

	for (int i = 0; i < 5; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	int E[5] = {0};

	for (int i = 0; i < 5; i++) {
		cout << E[i] << " ";
	}

	cout << endl;

	int F[5];

	memset(F, 0, sizeof(F));

	for (int i = 0; i < 5; i++) {
		cout << F[i] << " ";
	}

	cout << endl;


	return 0;
};