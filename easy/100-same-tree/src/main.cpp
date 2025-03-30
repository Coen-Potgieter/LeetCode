

#include <vector>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool inorderTravesal(TreeNode* node1, TreeNode* node2) {

        bool isSame = true;

        // Check Value
        if (node1->val != node2->val) return false;

        // If both have left then check left
        if (node1->left && node2->left) {
            isSame = inorderTravesal(node1->left, node2->left);
        } else if (!node1->left && !node2->left) {
            // If the both null then check right
        } else {
            return false;
        }

        if (!isSame) return false;

        // If both have right then check right
        if (node1->right && node2->right) {
            isSame = inorderTravesal(node1->right, node2->right);
        } else if (!node1->right && !node2->right) {
            // Do nothing
        } else {
            return false;
        }
        if (!isSame) return false;

        return true;


    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (!p && !q) {
            return true;
        } else if (p && q) {

        } else {
            return false;
        }

        return inorderTravesal(p, q);
    }
};

int main() {



    TreeNode *leaf1 = new TreeNode(2);
    TreeNode *leaf2 = new TreeNode(3);
    TreeNode *root1 = new TreeNode(1, leaf1, leaf2);
    TreeNode *leaf3 = new TreeNode(2);
    TreeNode *leaf4 = new TreeNode(3);
    TreeNode *root2 = new TreeNode(1, leaf3, leaf4);

    Solution mySol;

    bool outp = mySol.isSameTree(root1, root2);

    if (outp) std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;

    return 0;

}
