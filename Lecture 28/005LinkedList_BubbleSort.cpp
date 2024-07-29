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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

int computeLengthIterative(ListNode* head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

// time : O(n^2)
// space: O(1)

ListNode* bubbleSort(ListNode* head) {

	int n = computeLengthIterative(head); // n-steps

	int i = 1;
	while (i < n) { // n^2 cmp
		int j = 0;
		ListNode* prev = NULL;
		ListNode* cur = head;
		while (j < n - i) {
			ListNode* temp = cur->next;
			if (cur->val > temp->val) {
				// swap cur and temp node
				cur->next = temp->next;
				temp->next = cur;
				if (prev == NULL) {
					head = temp;
				} else {
					prev->next = temp;
				}
				prev = temp;
			} else {
				// don't swap cur and temp node
				prev = cur;
				cur = cur->next;
			}
			j++;
		}
		i++;
	}

	return head;
}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLinkedList(head);

	head = bubbleSort(head);

	printLinkedList(head);

	return 0;
}