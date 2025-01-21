



#include <stdexcept>
#include <vector>
#include <iostream>
#include <optional>
#include <queue>

/* * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
private:

    bool bfs(TreeNode* root, int target) {

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* currNode = q.front(); q.pop();

            if (currNode->val == target) {
                return true;
            }

            if (currNode->left) q.push(currNode->left);
            if (currNode->right) q.push(currNode->right);
        }
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // check left subtree


        bool bothLeft = false;
        if (root->left) {
            bothLeft = (bfs(root->left, p->val) & bfs(root->left, q->val));
        }
        if (bothLeft) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // if not not both right then check if both right...
        bool bothRight = false;
        if (root->right) {
            bothRight = (bfs(root->right, p->val) & bfs(root->right, q->val));
        }
        if (bothRight) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // if neither both right nor both left, then answer must be the node we are currently ont right?????
        return root;
    }
};


void printTree(TreeNode* root) {

    // print bfs
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        TreeNode* currNode = q.front();
        q.pop();

        if (!currNode) {
            std::cout << "null, ";
            continue;
        } else {
            std::cout << currNode->val << ", ";
        }

        q.push(currNode->left);
        q.push(currNode->right);
    }

}

TreeNode* createTree(const std::vector<std::optional<int>>& inpArr) {



    int dataVal;
    TreeNode* root = nullptr;
    int numNulls = 0;
    int nullsSeen = 0;

    for (int i = 0; i < inpArr.size(); i++) {

        if (!inpArr[i].has_value()) {
            std::cout << "NULL VALUE -> Do Nothing..." << std::endl;
            numNulls += 1;
            continue;
        }

        dataVal = *inpArr[i];
        std::cout << "Creating Node #" << i << " With Data Value: " << dataVal << std::endl;

        TreeNode* newNode = new TreeNode(dataVal);

        if (!root) {
            root = newNode;
        } else {

            nullsSeen = 0;
            // bfs to insert at nullptr
            std::queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                TreeNode* currNode = q.front();
                q.pop();

                if (currNode->left) {
                    q.push(currNode->left);
                } else {
                    if (nullsSeen >= numNulls) {
                        currNode->left = newNode;
                        break;
                    }
                    nullsSeen += 1;
                }
                if (currNode->right) {
                    q.push(currNode->right);
                } else {
                    if (nullsSeen >= numNulls) {
                        currNode->right = newNode;
                        break;
                    }
                    nullsSeen += 1;
                }
            }
        }

    }
    return root;
}

TreeNode* deleteTree(TreeNode* root, bool silent) {



    if (!root) return nullptr;

    root->left = deleteTree(root->left, silent);
    root->right = deleteTree(root->right, silent);

    if (!silent) {
        std::cout << "Deleting Node With Value: " << root->val << std::endl;
    }
    delete root;

    return nullptr;
}

TreeNode* findNode(TreeNode* root, int element) {

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        TreeNode* currNode = q.front();
        q.pop();

        if (currNode->val == element) {
            return currNode;
        }

        if (currNode->left) q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);
    }

    std::string outpError = "Could not find node with value: " + std::to_string(element);
    throw std::invalid_argument(outpError);
}




int main() {

    std::vector<std::optional<int>> tree1 = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
    int p1 = 5;
    int q1 = 8;
    int p2 = 5;
    int q2 = 4;

    std::vector<std::optional<int>> tree = tree1;

    std::cout << "\nCreating Tree..." << std::endl;
    TreeNode* root = createTree(tree);

    std::cout << "\nPrinting Tree..." << std::endl;
    printTree(root);


    TreeNode* p = findNode(root, p2);
    TreeNode* q = findNode(root, q2);



    Solution sol;




    std::cout << "\n\n";
    std::cout << "Input:\nTree: ";
    for (const auto& elem : tree) {
        if (elem.has_value()) {
            std::cout << *elem << ", ";
        } else {
            std::cout << "null, ";

        }
    }
    std::cout << std::endl;
    std::cout << "p: " << p->val << std::endl;
    std::cout << "q: " << q->val << std::endl;

    std::cout << "\nOutput: " << sol.lowestCommonAncestor(root, p, q)->val << std::endl;

    std::cout << "\n\nDeleting Tree..." << std::endl;
    deleteTree(root, true);
    return 0;







}
