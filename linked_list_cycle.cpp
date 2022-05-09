#include <iostream>

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr) { }
};

ListNode * middleNode (ListNode * head) {
    ListNode * fast = head;
    ListNode * slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

bool hasCycle (ListNode * head) {   
    ListNode * fast = head;
    ListNode * slow = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main () {
    
    ListNode * l1 = new ListNode(3);
    ListNode * l2 = new ListNode(2);
    ListNode * l3 = new ListNode(0);
    ListNode * l4 = new ListNode(-4);
    ListNode * l5 = new ListNode(3);
    ListNode * l6 = new ListNode(2);
    ListNode * l7 = new ListNode(0);
    ListNode * l8 = new ListNode(-4);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = nullptr;

    if (hasCycle(l1))
        std::cout << "Cycle found in list, immediate DANGER" << std::endl;
    else
        std::cout << "No cycles detected, safe to proceed" << std::endl;
   
    ListNode * result = middleNode(l1);
    
    std::cout << "Expected node with val 3, got node with val " << result->val  << std::endl;


    delete l1;
    delete l2;
    delete l3;
    delete l4;
    delete l5;
    delete l6;
    delete l7;
    delete l8;

    return 0;
}
