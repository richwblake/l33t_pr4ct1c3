#include <iostream>

struct Listnode {
    int val;
    Listnode * next;
    Listnode(int x) : val(x), next(nullptr) { }
};

void printList (Listnode * n) {
    std::cout << "{ ";
    while (n) {
        std::cout << n->val << " ";
        n = n->next;
    }
    std::cout << "}" << std::endl;
}

bool isPalindrome (Listnode * n) {
    Listnode * slow = n;
    Listnode * fast = n;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Listnode * current = slow->next;
    Listnode * prev = nullptr, * next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    while (prev) {
        if (n->val != prev->val)
            return false;
        n = n->next;
        prev = prev->next;
    }
    return true;
}

int main () {
    
    Listnode * l1 = new Listnode(1);
    Listnode * l2 = new Listnode(5);
    Listnode * l3 = new Listnode(7);
    Listnode * l4 = new Listnode(3);
    Listnode * l5 = new Listnode(1);
    Listnode * l6 = new Listnode(5);
    Listnode * l7 = new Listnode(6);
    Listnode * l8 = new Listnode(3);
    Listnode * l9 = new Listnode(7);
    Listnode * l10 = new Listnode(2);

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

    std::cout << (isPalindrome(l1) ? "true" : "false") << std::endl;;

    return 0;
}
