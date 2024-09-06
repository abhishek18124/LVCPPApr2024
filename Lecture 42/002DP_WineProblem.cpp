/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>

using namespace std;

int f(vector<int> p, int i, int j, int y) {

	// base case

	// todo ...

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// todo ...

}

int main() {

	vector<int> p = {2, 3, 5, 1, 4};
	int n = p.size();

	cout << f(p, 0, n - 1, 1) << endl;

	return 0;
}