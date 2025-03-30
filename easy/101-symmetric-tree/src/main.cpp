
#include <iostream>
#include <queue>
#include <vector>

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

    void printVec(std::vector<int>& v) {
        for (const int& elem : v) {
            std::cout << elem << " ";
        }
    std::cout << std::endl;

    }

    std::vector<int> bfs(TreeNode* node, bool leftFirst) {

        std::vector<int> outpVec;
        std::queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if (currNode) outpVec.push_back(currNode->val);
            else {
                outpVec.push_back(-101);
                continue;
            }

            if (leftFirst) {
                q.push(currNode->left);
                q.push(currNode->right);
            } else {
                q.push(currNode->right);
                q.push(currNode->left);
            }
        }

        return outpVec;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right) {
            return true;
        } else if (root->left && root->right) {

        } else {
            return false;
        }

        std::vector<int> bfsOutptL = bfs(root->left, true);
        std::vector<int> bfsOutptR = bfs(root->right, false);

        return std::equal(bfsOutptL.begin(), bfsOutptL.end(), bfsOutptR.begin());


    }
};

int main() {

    TreeNode *leaf1 = new TreeNode(3);
    TreeNode *leaf2 = new TreeNode(4);
    TreeNode *node1 = new TreeNode(2, leaf1, leaf2);

    TreeNode *leaf3 = new TreeNode(4);
    TreeNode *leaf4 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2, leaf3, leaf4);

    TreeNode *root = new TreeNode(1, node1, node2);

    /* TreeNode *leaf1 = new TreeNode(6); */
    /* TreeNode *node1 = new TreeNode(5, leaf1, nullptr); */
    /* TreeNode *node2 = new TreeNode(4, node1, nullptr); */

    /* TreeNode *leaf2 = new TreeNode(6); */
    /* TreeNode *node3 = new TreeNode(5, nullptr, leaf2); */
    /* TreeNode *node4 = new TreeNode(4, nullptr, node3); */

    /* TreeNode *root = new TreeNode(3, node2, node4); */

    Solution mySol;

    bool outp = mySol.isSymmetric(root);

    if (outp) std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;
    return 0;
}
