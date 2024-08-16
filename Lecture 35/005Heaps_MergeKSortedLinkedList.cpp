/*

    Given k sorted linked list, merge them and print the sorted output.

    k = 3
    Input : 1->3->5
            2->4->6
            0->8->7

    Output: 0->1->2->3->4->5->6->7->8

*/

#include<iostream>
#include<queue>
#include<vector>

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

class ListNodeComparator {

public:

    // return true if you want a to be orrdered before b otherwise false

    // return false if you want a to be given higher priority than b otherwise return true

    bool operator()(ListNode* a, ListNode* b) {

        if (a->val < b->val) {

            // we want to give higher priority to a since we are building a minHeap

            return false;

        }

        return true;

    }

};

// time = (nk push + nk pop).logk + (nk top).c // O(nklogk)
// space= O(k) due to minHeap

ListNode* mergeKSortedLinkedList(const vector<ListNode*>& v) {

    priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> minHeap(v.begin(), v.end());

    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    while (!minHeap.empty()) {

        ListNode* minValNode = minHeap.top();
        minHeap.pop();

        temp->next = minValNode;
        temp = temp->next;

        if (minValNode->next != NULL) {
            minHeap.push(minValNode->next);
        }

    }

    return dummy->next;

}

int main() {

    ListNode* head1 = NULL;

    insertAtHead(head1, 7);
    insertAtHead(head1, 4);
    insertAtHead(head1, 1);

    printLinkedList(head1);

    ListNode* head2 = NULL;

    insertAtHead(head2, 8);
    insertAtHead(head2, 5);
    insertAtHead(head2, 2);

    printLinkedList(head2);

    ListNode* head3 = NULL;

    insertAtHead(head3, 9);
    insertAtHead(head3, 6);
    insertAtHead(head3, 3);

    printLinkedList(head3);

    vector<ListNode*> v = {head1, head2, head3}; // size of v[] is k

    ListNode* head = mergeKSortedLinkedList(v);

    printLinkedList(head);

    return 0;
}
