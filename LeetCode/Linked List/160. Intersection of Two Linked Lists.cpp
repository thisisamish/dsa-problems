// Written By - Amish Verma (@thisisamish)
// TC is O(n), SC is O(1)

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
    int lengthOfLL(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            count++;
        }
        if (fast == NULL) return count * 2;
        return (count * 2) + 1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        int lenA = lengthOfLL(headA), lenB = lengthOfLL(headB);
        ListNode* currA = headA, *currB = headB;

        while (lenA > lenB) {
            currA = currA->next;
            lenA--;
        }
        while (lenB > lenA) {
            currB = currB->next;
            lenB--;
        }

        while (currA) {
            if (currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
};