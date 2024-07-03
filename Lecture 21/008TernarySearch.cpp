#include<iostream>
#include<iomanip>

using namespace std;

int f(int x) {
	return -x * x + 100 * x; // -x^2 + 100x is a unimodal function
}

// double findPeak(double s, double e) {

// 	while (s < e) {
// 		double m1 = s + (e - s) / 3;
// 		double m2 = e - (e - s) / 3;

// 		cout << s << " " << e << " " << (s == e) << endl;

// 		if (f(m1) < f(m2)) {
// 			s = m1;
// 		} else {
// 			e = m2;
// 		}

// 	}

// 	return f((s + e) / 2);

// }

double findPeakRecursive(double s, double e) {

	// base case

	if (e - s <= 1e-6) {

		return f((s + e) / 2);

	}

	// recursive case

	double m1 = s + (e - s) / 3;
	double m2 = e - (e - s) / 3;

	if (f(m1) < f(m2)) {
		return findPeakRecursive(m1, e);
	}

	return findPeakRecursive(s, m2);

}

int main() {

	// cout << setprecision(20) << fixed;

	cout << findPeakRecursive(0, 100) << endl;

	return 0;
}