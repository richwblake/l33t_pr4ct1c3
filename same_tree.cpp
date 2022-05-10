#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree (TreeNode * p, TreeNode * q);

int main () {

    TreeNode * t1 = new TreeNode(1);
    TreeNode * t2 = new TreeNode(2);
    TreeNode * t3 = new TreeNode(3);
    
    TreeNode * m1 = new TreeNode(1);
    TreeNode * m2 = new TreeNode(2);
    TreeNode * m3 = new TreeNode(3);

    t1->left = t2;
    t1->right = t3;

    m1->left = m2;
    m1->right = m3;

    std::cout << "Expected true, got " << (isSameTree(t1, m1) ? "true" : "false") << std::endl;

    t2->val = 3;

    std::cout << "Expected false, got " << (isSameTree(t1, m1) ? "true" : "false") << std::endl;

    return 0;
}

bool isSameTree (TreeNode * p, TreeNode * q) {
    if (p==nullptr && q==nullptr) return true;
    if (p==nullptr || q==nullptr) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
}
