#include <iostream>

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int i) : val(i), next(nullptr) { }
};

ListNode * remove_duplicates (ListNode * head) {
    ListNode * slow = head;
    ListNode * fast = head->next;

    while (fast) {
        if (slow->val == fast->val) {
           slow->next = fast->next;
           delete fast;
           fast = slow->next;
        } else {
            slow = slow->next;
            fast = fast->next;
        }

    }
    return head;
}

void printList (ListNode * head) {
    std::cout << "{ ";
    while (head) {
        std::cout << head->val << " -> ";
        if (!head->next) std::cout << "nullptr ";
        head = head->next; 
    }
    std::cout << "}" << std::endl;
}

int main () {

    ListNode * l1 = new ListNode (1);
    ListNode * l2 = new ListNode (1);
    ListNode * l3 = new ListNode (9);
    ListNode * l4 = new ListNode (9);
    ListNode * l5 = new ListNode (23);
    ListNode * l6 = new ListNode (23);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;

    printList(l1);

    printList(remove_duplicates(l1));

    return 0;
}
