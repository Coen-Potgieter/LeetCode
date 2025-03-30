

#include <vector>
#include <iostream>
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:

    std::vector<Node*> getBFS(Node* head) {

        std::vector<Node*> outp;
        std::queue<Node*> q;
        q.push(head);

        while (!q.empty()) {
            Node* currNode = q.front();
            q.pop();

            outp.push_back(currNode);
            if (currNode->left) q.push(currNode->left);
            if (currNode->right) q.push(currNode->right);
        }

        return outp;
    }

    Node* connect(Node* root) {

        if (root == nullptr) {
            return nullptr;
        }

        std::vector<Node*> bfsVec = getBFS(root);
        if (bfsVec.size() == 1) {
            return root;
        }

        int startNode = 1;
        int lastNode = 2;
        int numLayer = 1;

        while (1) {
            lastNode = startNode + std::pow(2, numLayer) - 1;
            for (int i = startNode; i < lastNode; i++) {
                bfsVec[i]->next = bfsVec[i+1];
            }
            startNode = lastNode + 1;
            numLayer += 1;
            if (startNode >= bfsVec.size()) {
                break;
            }
        }
        return root;
    }
};

Node* createTree(std::vector<int> inp);
void printTree(Node* head);

int main() {

    std::vector<int> inpVec = { 1,2,3,4,5,6 };

    Node* head = createTree(inpVec);
    printTree(head);

    Solution mySol;

    Node* newHead = mySol.connect(head);
    return 0;
} 


void printTree(Node* head) {

    std::queue<Node*> q;
    q.push(head);

    while (!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        std::cout << currNode->val << ", ";
        if (currNode->left) q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);
    }
}
void insertBST(Node* root, int newValue) {

    if (root->val < newValue) {
        if (root->left != nullptr) {
            insertBST(root->left, newValue);
        } else {
            Node* newNode = new Node(newValue);
            root->left = newNode;
        }
    } else {
        if (root->right != nullptr) {
            insertBST(root->right, newValue);
        } else {
            Node* newNode = new Node(newValue);
            root->right = newNode;
        }
    }

}

Node* createTree(std::vector<int> inp) {

    Node *head = new Node(inp[0]);

    for (size_t ptr = 1; ptr < inp.size(); ptr++) {
        insertBST(head, inp[ptr]);
    }

    return head;
}


