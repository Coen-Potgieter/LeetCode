

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // EdgeCases
        if ((!list1) &&  (!list2)) return nullptr;
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* myList = new ListNode();
        // First node
        if (list1->val <= list2->val) {
            std::cout << "Insterted From List1\n";
            myList->val = list1->val;
            list1 = list1->next;
        } else {
            std::cout << "Insterted From List2\n";
            myList->val = list2->val;
            list2 = list2->next;
        }
        ListNode* myListRoot = myList;

        while ((list1) || (list2)) {
            myList->next = new ListNode();
            myList = myList->next;

            if (!list1) std::cout << "LIST 1 EMPTY\n";
            if (!list2) std::cout << "LIST 2 EMPTY\n";
            // If list1 is empty then just append current with list other
            if (!list1) {
                std::cout << "Insterted From List2\n";
                myList->val = list2->val;
                list2 = list2->next;
            } else if (!list2) {
                // If list2 is empty then just append current with list other
                std::cout << "Insterted From List1\n";
                myList->val = list1->val;
                list1 = list1->next;
            } else if (list1->val <= list2->val) {
                std::cout << "Insterted From List1\n";
                myList->val = list1->val;
                list1 = list1->next;
            } else {
                std::cout << "Insterted From List2\n";
                myList->val = list2->val;
                list2 = list2->next;
            }

        }

        return myListRoot;
    }
};
