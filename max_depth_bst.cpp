#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printLevelOrder (TreeNode * root) {
    std::queue<TreeNode*> queue;

    queue.push(root);

    std::cout << "{ ";
    while (queue.empty() == false) {
        TreeNode * current = queue.front();
        queue.pop();

        std::cout << current->val << " ";

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);
    }
    std::cout << "}" << std::endl;
}

int maxDepth (TreeNode * root) {
    if (root->left == nullptr && root->right == nullptr) return 1;
    int leftDepth = 1 + maxDepth(root->left);
    int rightDepth = 1 + maxDepth(root->right);
    std::cout << "leftDepth: " << leftDepth << "\n";
    std::cout << "rightDepth: " << rightDepth << std::endl;
    return leftDepth > rightDepth ? leftDepth : rightDepth;
}

int main () {


    TreeNode * root = new TreeNode(3);
    TreeNode * l1 = new TreeNode(9);
    TreeNode * r1 = new TreeNode(20);
    TreeNode * rl1 = new TreeNode(15);
    TreeNode * rl2 = new TreeNode(7);

    root->left = l1;
    root->right = r1;
    r1->left = rl1;
    r1->right = rl2;

    printLevelOrder(root);

    std::cout << "Expected 3, got " << maxDepth(root) << std::endl;

    return 0;
}
