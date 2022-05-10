#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

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

std::vector<double> averageOfLevels (TreeNode * root) {
    std::vector<double> avgs;
    std::queue<TreeNode*> queue;

    queue.push(root);

    while (!queue.empty()) {
        double avg = 0;
        int qSize = queue.size();

        for (int i = 0; i < qSize; i++) {
            TreeNode * current = queue.front();
            queue.pop();

            avg += current->val;

            if (current->left) queue.push(current->left);
            if (current->right) queue.push(current->right);
        }
        avgs.push_back(avg / qSize);
    }   

    return avgs;
}

void printVector (std::vector<double>& results) {
    int len = results.size();

    std::cout << "[";
    for (int i = 0; i < len; i++) {
        std::cout << " " << results[i];
    }
    std::cout << " ]" << std::endl;
}

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

    std::vector<double> results = averageOfLevels(root);

    printVector(results);

    return 0;
}
