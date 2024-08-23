/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int countTriangles(const vector<Point>& points) {

	// time : O(n^2)

	int cnt = 0;

	for (Point pivot : points) {

		// count the no. of axis parallel right angled triangles around the pivot

		int a = 0; // to track no. of points in the 2D plane whose x-coor matches pivot.x
		int b = 0; // to track no. of points in the 2D plane whose y-coor matches pivot.y

		for (Point pt : points) {
			if (pt.x == pivot.x) {
				a++;
			}
			if (pt.y == pivot.y) {
				b++;
			}
		}

		cnt += (a - 1) * (b - 1);

	}

	return cnt;
}

// time : O(n)
// space: O(n) due to xFreqMap and yFreqMap

int countTrianglesOptimised(const vector<Point>& points) {

	unordered_map<int, int> xFreqMap;
	unordered_map<int, int> yFreqMap;

	for (Point pt : points) {
		xFreqMap[pt.x]++;
		yFreqMap[pt.y]++;
	}

	int cnt = 0;

	for (Point pivot : points) {

		// count the no. of axis parallel right angled triangles around the pivot

		int a = xFreqMap[pivot.x]; // to track no. of points in the 2D plane whose x-coor matches pivot.x
		int b = yFreqMap[pivot.y]; // to track no. of points in the 2D plane whose y-coor matches pivot.y

		cnt += (a - 1) * (b - 1);

	}

	return cnt;

}

int main() {

	vector<Point> points = {
		Point(1, 2),
		Point(2, 0),
		Point(2, 2),
		Point(2, 3),
		Point(4, 2)
	};

	cout << countTriangles(points) << endl;

	cout << countTrianglesOptimised(points) << endl;

	return 0;
}