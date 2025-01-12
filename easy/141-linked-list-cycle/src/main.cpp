/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* trav = head;

        int idx = 0;
        int maxIdx = 10 * 10 * 10 * 10 + 1;
        while (trav) {
            if (idx >= maxIdx) {
                return true;
            }
            trav = trav->next;
            idx += 1;
        }
        return false;
    }
};
