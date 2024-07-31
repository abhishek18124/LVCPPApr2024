#include<iostream>
#include<list>

using namespace std;

// head of dll = front of the queue
// tail of dll = rear of the queue

// q.push(val) => insertion at the tail of the dll i.e. dll.push_back(val)
// q.pop() => deletion at the head of the dll i.e. dll.pop_front();
// q.front() => value of the head node i.e. dll.front()

template <typename T>
class queue {

	list<T> dll;

public:

	void push(T val) {
		dll.push_back(val);
	}

	void pop() {
		if (empty()) {
			// queue is empty
			return;
		}
		dll.pop_front();
	}

	T front() {
		return dll.front();
	}

	int size() {
		return dll.size();
	}

	bool empty() {
		return dll.empty();
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