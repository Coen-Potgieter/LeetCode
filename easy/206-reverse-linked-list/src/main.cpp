
#include <vector>
#include <iostream>

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
    ListNode* reverseList(ListNode* head) {

        ListNode* trav = head;
        ListNode* changer = nullptr;
        ListNode* changeTo = nullptr;

        while (trav || changer || changeTo) {

            if (changer) {
                changer->next = changeTo;
            }
            changeTo = changer;
            changer = trav;
            trav = (trav) ? trav->next : nullptr;

            if ((changeTo) && (!changer) && (!trav)) {
                head = changeTo;
            }
        }
        return head;

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
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    Solution mySol;

    ListNode* reveresedList = mySol.reverseList(head);
    printList(reveresedList);

    clean(head);


    return 0;
}
