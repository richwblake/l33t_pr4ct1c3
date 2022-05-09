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

ListNode * merge_lists (ListNode * list1, ListNode * list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    ListNode * start = list1;

    if (list1->val > list2->val) {
        start = list2;
        list2 = list2->next;
    } else {
        list1 = list1->next;
    }

    ListNode * current = start;

    while (list1 && list2) {
        if (list1->val > list2->val) {
            current->next = list2;
            list2 = list2->next;
        } else {
            current->next = list1;
            list1 = list1->next;
        }
        current = current->next;
    }

    if (list1)
        current->next = list1;
    else
        current->next = list2;

    return start;
}

int main () {

    ListNode * l1 = new ListNode(1);
    ListNode * l2 = new ListNode(2);
    ListNode * l3 = new ListNode(4);

    ListNode * m1 = new ListNode(1);
    ListNode * m2 = new ListNode(3);
    ListNode * m3 = new ListNode(4);


    l1->next = l2;
    l2->next = l3;
    l3->next = nullptr;

    m1->next = m2;
    m2->next = m3;
    m3->next = nullptr;

    std::cout << "Before merger" << "\n";
    std::cout << "List 1: "; 
    printList(l1);
    std::cout << "List 2: "; 
    printList(m1);

    std::cout << "After merger" << "\n" << "Merged List: ";
    printList(merge_lists(l1, m1));

    return 0;
}

















