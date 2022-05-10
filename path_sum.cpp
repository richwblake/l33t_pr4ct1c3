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

bool hasPathSum (TreeNode * root, int targetSum);

void printLevelOrderOfBinaryTree (TreeNode * root);

int main () {

    TreeNode * root = new TreeNode(3);
    TreeNode * nine = new TreeNode(9);
    TreeNode * twenty = new TreeNode(20);
    TreeNode * fifteen = new TreeNode(15);
    TreeNode * seven = new TreeNode(7);

    root->left = nine;
    root->right = twenty;
    twenty->left = fifteen;
    twenty->right = seven;

    printLevelOrderOfBinaryTree(root);

    bool hasSum = hasPathSum(root, 30);

    std::cout << "Expected true, got " << (hasSum ? "true" : "false") << std::endl;

    twenty->val = 23;

    hasSum = hasPathSum(root, 30);

    std::cout << "Expected false, got " << (hasSum ? "true" : "false") << std::endl;


    return 0;
}

bool pathSumChecker (TreeNode * node, int targetSum, int currentSum) {
    if (!node) return false;
    if (node->left == nullptr && node->right == nullptr) return currentSum + node->val == targetSum;
    return pathSumChecker(node->left, targetSum, currentSum + node->val) || pathSumChecker(node->right, targetSum, currentSum + node->val);
}

bool hasPathSum (TreeNode * root, int targetSum) {
    return pathSumChecker(root, targetSum, 0);
}

void printLevelOrderOfBinaryTree (TreeNode * root) {
    std::queue<TreeNode*> queue;

    queue.push(root);

    while (queue.empty() == false) {
        TreeNode * current = queue.front();
        queue.pop();
        std::cout << current->val << " ";

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);
    }
    std::cout << std::endl;
}
