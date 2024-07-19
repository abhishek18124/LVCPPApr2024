#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};


void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

void deleteAtHead(ListNode*& head) {

	if (!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
}

ListNode* getNode(ListNode* head, int j) {

	// return the address of the node present at the jth index of the given LinkedList

	int k = 1;
	while (head != NULL and k <= j) {
		head = head->next;
		k++;
	}

	return head;

}

// time : O(n) due to getNode()

void deleteAtIndex(ListNode*& head, int i) {

	if (i == 0) {
		deleteAtHead(head);
		return;
	}

	ListNode* prev = getNode(head, i - 1);
	if (prev == NULL) {
		// i > len of LinkedList
		return;
	}

	ListNode* cur = getNode(head, i); // prev->next
	if (cur == NULL) {
		// i >= len of the LinkedList
		return;
	}

	prev->next = cur->next;
	delete cur;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtIndex(head, 0);

	printLinkedList(head);

	return 0;
}