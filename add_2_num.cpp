#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while ( l1 != nullptr || l2 != nullptr || carry > 0 ) {
            int val1 = (l1 != nullptr) ? l1 -> val : 0;
            int val2 = (l2 != nullptr) ? l2 -> val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            current -> next = new ListNode(sum % 10);

            current = current -> next;

            if (l1 != nullptr) l1 = l1 -> next;
            if (l2 != nullptr) l2 = l2 -> next;
        }
        return dummy -> next;
    }
};

void display(ListNode* head) {
    while (head != nullptr) {
        cout << head -> val;
        if (head -> next != nullptr) cout << " -> ";
        head = head -> next;
    }
    cout << endl;
}

ListNode* createLinkedList() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n == 0) return nullptr;

    cout << "Enter the values of the linked list nodes (in reverse order):" << endl;

    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* current = head;

    for (int i = 1; i < n; ++i) {
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }

    return head;
}

int main() {
    cout << "Input for the first linked list (l1):" << endl;
    ListNode* l1 = createLinkedList();

    cout << "Input for the second linked list (l2):" << endl;
    ListNode* l2 = createLinkedList();

    Solution solution;

    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Result Linked List: ";
    display(result);

    delete l1;
    delete l2;
    delete result;

    return 0;
}