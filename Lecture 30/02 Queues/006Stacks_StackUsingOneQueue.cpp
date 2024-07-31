/*

Implementation of the stack using two queues.

*/

#include<iostream>
#include<queue>

using namespace std;

template <typename T>
class stack {

	queue<T> q;

public:

	void push(T data) {
		q.push(data);
	}

	void pop() {

		int n = size(); // q.size()

		// transfer n-1 elements from q to q

		while (n > 1) {

			q.push(q.front());
			q.pop();

			n--;

		}


		// front of the queue represents the top of the stack
		q.pop();
	}

	T top() {
		return q.back();
	}

	bool empty() {
		return q.empty();
	}

	int size() {
		return q.size();
	}
};

int main() {

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << "size = " << s.size() << endl;

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

	s.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}