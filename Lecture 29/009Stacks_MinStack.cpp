#include<iostream>
#include<stack>

using namespace std;

// hw : try to implement custom stack without using extra space ( min_stack ) and still const time
// think how you can track potential minimum in main stack itself

class custom_stack {

	stack<int> main_stack;
	stack<int> min_stack; // to track all the potential minimums

public :

	void push(int val) { // const
		main_stack.push(val);
		if (min_stack.empty() || val <= min_stack.top()) {
			min_stack.push(val);
		}
	}

	void pop() { // const
		if (empty()) {
			return;
		}
		int temp = main_stack.top();
		main_stack.pop();
		if (min_stack.top() == temp) {
			min_stack.pop();
		}
	}

	int size() {
		return main_stack.size();
	}

	bool empty() {
		return main_stack.empty();
	}

	int top() {
		return main_stack.top();
	}

	int getMin() { // const
		return min_stack.top();
	}

};

int main() {

	custom_stack cs;

	cs.push(10);
	cs.push(20);

	// cout << cs.getMin() << endl;

	cs.push(5);
	cs.push(30);

	// cout << cs.getMin() << endl;

	cs.push(0);
	cs.push(0);

	cout << cs.getMin() << endl;

	cs.pop();
	// cs.pop();

	cout << cs.getMin() << endl;

	cs.pop();
	cs.pop();

	cout << cs.getMin() << endl;

	return 0;
}
