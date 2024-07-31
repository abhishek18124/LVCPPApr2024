#include<iostream>
#include<deque>

using namespace std;

template <typename T>
class queue {

	deque<T> d;

public:

	void push(T val) {
		d.push_back(val);
	}

	void pop() {
		if (empty()) {
			// queue is empty
			return;
		}
		d.pop_front();
	}

	T front() {
		return d.front(); // d[0]
	}

	int size() {
		return d.size();
	}

	bool empty() {
		return d.empty();
	}

};

int main() {

	queue<int> q;

	cout << "size : " << q.size() << endl;
	cout << "empty : " << q.empty() << endl;

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();
	q.empty() ? cout << "queue is empty!" << endl : cout << "queue is not empty!" << endl;

	return 0;
}