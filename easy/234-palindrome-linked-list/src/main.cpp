
#include <iostream>
#include <vector>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        std::vector<int> recordedVals;
        ListNode* trav = head;

        while (trav) {
            recordedVals.push_back(trav->val);
            trav = trav->next;
        }
        // Now check for palindrome on vector

        int mid = recordedVals.size() / 2;

        int bottomIdx = 0;
        int topIdx = recordedVals.size() - 1;

        for (int i = 0; i < mid; i++) {
            if (recordedVals[bottomIdx + i] != recordedVals[topIdx - i]) {
                return false;
            }
        }
        return true;

    }
};


void printList(ListNode* head) {
    ListNode* trav = head;

    while (trav) {
        std::cout << trav->val << ", ";
        trav = trav->next;
    }
    std::cout << std::endl;
} 

void clean(ListNode* head) {
    ListNode* trav = head;
    ListNode* tmp;

    while (trav) {
        tmp = trav;
        trav = trav->next;
        delete tmp;
    }
}
int main() {

    ListNode* head = new ListNode(10);
    /* head->next = new ListNode(20); */
    /* head->next->next = new ListNode(30); */
    /* head->next->next = new ListNode(20); */
    /* head->next->next->next = new ListNode(10); */
    /* head->next->next->next->next = new ListNode(50); */

    Solution mySol;

    bool res = mySol.isPalindrome(head);


    printList(head);
    std::cout << res << std::endl;

    clean(head);


    return 0;
}
