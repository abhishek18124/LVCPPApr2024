#include<iostream>

using namespace std;

template <typename T>
class ListNode {
public:

	T val;
	ListNode<T>* next;

	ListNode(T val) {
		this->val = val;
		this->next = NULL;
	}

};

template <typename T>
class forward_list {

	ListNode<T>* head;
	int  cnt;

public :

	forward_list() {
		head = NULL;
		cnt = 0;
	}

	void push_front(T val) {
		ListNode<T>* n = new ListNode<T>(val);
		n->next = head;
		head = n;
		cnt++;
	}

	void pop_front() {
		if (head == NULL) {
			// LinkedList is empty
			return;
		}

		ListNode<T>* temp = head;
		head = head->next;
		delete temp;
		cnt--;
	}

	int size() {
		return cnt;
	}

	bool empty() {
		return head == NULL; // cnt == 0
	}

	T front() { // if you call front() on empty linkedList it is undefined
		return head->val;
	}

	void traverse() {
		ListNode<T>* temp = head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

};

int main() {

	forward_list<char> fw;

	fw.push_front('e');
	fw.push_front('d');
	fw.push_front('c');
	fw.push_front('b');
	fw.push_front('a');

	cout <<  "head->val : " << fw.front() << endl;

	fw.traverse();

	cout << "size : " << fw.size() << endl;

	fw.pop_front();
	fw.pop_front();

	cout <<  "head->val : " << fw.front() << endl;

	fw.traverse();

	cout << "size : " << fw.size() << endl;

	fw.pop_front();
	fw.pop_front();
	fw.pop_front();

	fw.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}


