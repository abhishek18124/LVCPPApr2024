#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class stack {

	vector<T> v;

public :

	void push(T val) {
		v.push_back(val);
	}

	void pop() {
		if (empty()) {
			return;
		}
		v.pop_back();
	}

	int size() {
		return v.size();
	}

	T top() {
		return v.back(); // return v[v.size()-1];
	}

	bool empty() {
		return v.empty(); // v.size() == 0
	}

};

int main() {

	stack<string> s;

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.push("abc");
	s.push("def");
	s.push("ghi");
	s.push("jkl");
	s.push("mno");

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	return 0;
}