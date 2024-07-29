#include<iostream>

using namespace std;

class ListNode {
public:

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

// time : O(n)
// space: O(n) due to function call stack when there are no duplicates in the given linkedList
// hw : try to solve this problem iteratively [refer leetcode]

ListNode* removeDuplicates(ListNode* head) {

	// base case

	if (head == NULL || head->next == NULL) {

		// LinkedList is empty or it has one node

		return head;

	}

	// recursive case

	// LinkedList has >= 2 nodes

	if (head->val != head->next->val) {

		// head node is not duplicate

		// ask your friend to delete all the duplicate nodes from the sublist that starts from the node which comes after the head node

		ListNode* headFromMyFriend = removeDuplicates(head->next);
		head->next = headFromMyFriend;
		return head;

	} else {

		// head node is duplicate

		while (head->next != NULL and head->val == head->next->val) {
			head = head->next;
		}

		// ask your friend to delete all the duplicate nodes from the sublist that starts from the node which comes after the head node

		ListNode* headFromMyFriend = removeDuplicates(head->next);
		return headFromMyFriend;

	}

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 20);
	insertAtHead(head, 10);
	insertAtHead(head, 10);
	insertAtHead(head, 10);

	printLinkedList(head);

	head = removeDuplicates(head);

	printLinkedList(head);

	return 0;
}