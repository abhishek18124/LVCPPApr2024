#include<iostream>
#include<iomanip>

using namespace std;

int f(int x) {
	return -x * x + 100 * x; // -x^2 + 100x is a unimodal function
}

double findPeakIterative(double s, double e) {

	while (e - s > 1e-6) {

		cout << s << " " << e << endl;

		double m1 = s + (e - s) / 3;
		double m2 = e - (e - s) / 3;

		if (f(m1) > f(m2)) {

			e = m2;

		} else {

			// f(m1) < f(m2)

			s = m1;

		}

	}

	// e-s <= 1-6

	return f((s + e) / 2);

}

int main() {

	cout << setprecision(20) << fixed;

	cout << findPeakIterative(0, 100) << endl;

	return 0;
}