

#include <vector>
#include <iostream>
#include <algorithm> 

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

    void inorderTraversal(TreeNode* node, std::vector<int>& inpVec) {
        TreeNode *currNode = node;
        if (currNode->left) inorderTraversal(currNode->left, inpVec);
        inpVec.push_back(currNode->val);
        if (currNode->right) inorderTraversal(currNode->right, inpVec);
        return;
    }

    bool isValidBST(TreeNode* root) {

        std::vector<int> orderedNodes;
        inorderTraversal(root, orderedNodes);

        for (const int& elem : orderedNodes) {
            std::cout << elem << std::endl;
        }

        // Check for duplicates
        bool hasDups = false;
        size_t ptr2 = 1;
        for (int ptr1 = 0; ptr1 < orderedNodes.size() - 1; ptr1++) {
            if (orderedNodes[ptr1] == orderedNodes[ptr2]) {
                hasDups = true;
                break;
            }
            ptr2 += 1;
        }

        if (hasDups) return false;
        return std::is_sorted(orderedNodes.begin(), orderedNodes.end());

    }
};

int main() {


    /* TreeNode* leaf1 = new TreeNode(1); */
    /* TreeNode* leaf2 = new TreeNode(3); */
    /* TreeNode* leaf3 = new TreeNode(6); */
    
    /* TreeNode* node4 = new TreeNode(4, leaf2, leaf3); */
    /* TreeNode* root = new TreeNode(5, leaf1, node4); */

    /* TreeNode* leaf1 = new TreeNode(1); */
    /* TreeNode* leaf2 = new TreeNode(3); */
    /* TreeNode* root = new TreeNode(2, leaf1, leaf2); */
    
    TreeNode* leaf1 = new TreeNode(2);
    TreeNode* leaf2 = new TreeNode(2);
    TreeNode* root = new TreeNode(2, leaf1, leaf2);

    Solution mySol;
    bool outp = mySol.isValidBST(root);

    if (outp) std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;
    return 0;
}
