// Written By - Amish Verma (@thisisamish)
// TC is O(m + n), SC is O(1)

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
        if (!list1 || !list2) return list1 ? list1 : list2;

        ListNode* curr1 = list1, *curr2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (curr1 && curr2) {
            if (curr1->val <= curr2->val) {
                temp->next = curr1;
                temp = temp->next;
                curr1 = curr1->next;
            } else {
                temp->next = curr2;
                temp = temp->next;
                curr2 = curr2->next;
            }
        }

        while (curr1) {
            temp->next = curr1;
            temp = temp->next;
            curr1 = curr1->next;
        }
        while (curr2) {
            temp->next = curr2;
            temp = temp->next;
            curr2 = curr2->next;
        }

        return dummy->next;
    }
};