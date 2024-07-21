#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int add1(int y) {
	return 1 + y;
}

int add2(int y) {
	return 2 + y;
}

int add3(int y) {
	return 3 + y;
}

class addx {

	int x;

public:

	addx(int x) {
		this->x = x;
	}

	int operator()(int y) {
		return x + y;
	}

};

int main() {

	vector<int> inp = {1, 2, 3, 4, 5};

	for (int i = 0; i < inp.size(); i++) {
		cout << inp[i] << " ";
	}

	cout << endl;

	vector<int> out(inp.size());

	// addx obj1(1); // x is equal to 1

	// transform(inp.begin(), inp.end(), out.begin(), obj1);

	transform(inp.begin(), inp.end(), out.begin(), addx(1)); // we are passing an anonoymous obj

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	addx obj2(2);

	transform(inp.begin(), inp.end(), out.begin(), obj2);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	addx obj3(3);

	transform(inp.begin(), inp.end(), out.begin(), obj3);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;



	return 0;
}