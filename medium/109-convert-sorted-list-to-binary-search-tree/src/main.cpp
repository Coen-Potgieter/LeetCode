

#include <vector>
#include <iostream>
#include <queue>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ListNode* createLinkedList(std::vector<int> inp);
void printLinkedList(ListNode* start);
void printVec(std::vector<int> inp);
void printBFS(TreeNode* head);

class Solution {
public:

    std::vector<int> createVector(ListNode* start) {

        std::vector<int> outp;

        while (start != nullptr) {
            outp.push_back(start->val);
            start = start->next;
        }
        return outp;

    }
    void insertBST(TreeNode* root, int newValue) {

        /* TreeNode* newNode = new TreeNode(newValue); */


        // if new value is less than current node then traverse left
        if (newValue < root->val) {
            if (root->left != nullptr) {
                insertBST(root->left, newValue);
            } else {
                TreeNode *newNode = new TreeNode(newValue);
                root->left = newNode;
            }
        } else {
            if (root->right != nullptr) {
                insertBST(root->right, newValue);
            } else {
                TreeNode *newNode = new TreeNode(newValue);
                root->right = newNode;
            }
        }
        return;

    }

    void getOrderOfInsertions(std::vector<int>& order, int start, int end) {

        std::cout << "Start: " << start << " | End: " << end << " -> ";
        /* printVec(order); */
        if (end <= start) {
            /* std::cout << "Inserting: " << start << std::endl; */
            /* order.push_back(end); */
            std::cout << "return statement" << std::endl;
            return;
        }

        int median = (start + (end - start)/2);

        std::cout << "Inserting: " << median << std::endl;
        order.push_back(median);
        getOrderOfInsertions(order, start, median);
        /* return; */
        getOrderOfInsertions(order, median + 1, end);
        return;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        if (head == nullptr) {
            return nullptr;
        }


        // convert to list
        std::vector<int> vec = createVector(head);
        /* printVec(vec); */

        // Get Median
        size_t medianPtr = vec.size() / 2;
        /* std::cout << vec[medianPtr] << std::endl; */

        std::vector<int> order;
        std::cout << vec.size() << std::endl;
        getOrderOfInsertions(order, 0, vec.size());
        /* order.push_back(vec.size() - 1); */
        /* printVec(order); */



        TreeNode *treeHead = new TreeNode(vec[order[0]]);

        for (int ptr = 1; ptr < order.size(); ptr++) {
            insertBST(treeHead, vec[order[ptr]]);
        }

        return treeHead;


    }
};

int main() {


    std::vector<int> inp = { -10, -3, 0, 5, 9};
    /* std::vector<int> inp = {}; */
    /* std::vector<int> inp = {0,1,2,3,4,5}; */

    ListNode *start = createLinkedList(inp);
    /* printLinkedList(start); */

    Solution mySol;

    TreeNode* head = mySol.sortedListToBST(start);

    printBFS(head);

    return 0;
}

ListNode* createLinkedList(std::vector<int> inp) {

    if (inp.empty()) {
        return nullptr;
    }
    ListNode* start = new ListNode(inp[0]);
    ListNode* prev = start;

    for (size_t ptr = 1; ptr < inp.size(); ptr++) {
        ListNode *newNode = new ListNode(inp[ptr]);
        prev->next = newNode;
        prev = prev->next;
    }

    return start;
}

void printLinkedList(ListNode* start) {

    ListNode* currNode = start;
    while (currNode != nullptr) {
        std::cout << currNode->val << " -> ";
        currNode = currNode->next;
    }
    std::cout << std::endl;
}

void printVec(std::vector<int> inp) {
    std::cout << "[";
    for (const int& elem : inp) {
        std::cout << elem << ", ";
    }
    std::cout << "]" << std::endl;
}

void printBFS(TreeNode* head) {

    if (head == nullptr) {
        std::cout << "Null" << std::endl;
        return;
    }
    std::queue<TreeNode*> q;
    q.push(head);

    while (!q.empty()) {
        TreeNode *currNode = q.front();
        q.pop();

        std::cout << currNode->val << ", ";
        if (currNode->left) q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);
    }

}
