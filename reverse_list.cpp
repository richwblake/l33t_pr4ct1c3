#include <iostream>

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int i) : val(i), next(nullptr) { }
};

void printList (ListNode * head) {
    std::cout << "{ ";
    while (head) {
        std::cout << head->val << " -> ";
        if (!head->next) std::cout << "nullptr ";
        head = head->next; 
    }
    std::cout << "}" << std::endl;
}

ListNode * reverse_list (ListNode * head) {
    ListNode * next = nullptr;
    ListNode * prev = nullptr;
    ListNode * current = head;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

int main () {

    ListNode * l1 = new ListNode(1);
    ListNode * l2 = new ListNode(5);
    ListNode * l3 = new ListNode(7);
    ListNode * l4 = new ListNode(45);
    ListNode * l5 = new ListNode(15);
    ListNode * l6 = new ListNode(25);
    ListNode * l7 = new ListNode(13);
    ListNode * l8 = new ListNode(7);
    ListNode * l9 = new ListNode(67);
    ListNode * l10 = new ListNode(54);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = l9;
    l9->next = l10;
    l10->next = nullptr;

    printList(l1);

    printList(reverse_list(l1));

    return 0;
}
