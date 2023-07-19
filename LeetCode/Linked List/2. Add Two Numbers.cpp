// Written By - Amish Verma (@thisisamish)
// Approach 1 : Classic Merge approach
// TC is O(n) and SC is O(1)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem = 0;
        ListNode* res = new ListNode();
        ListNode* temp = res;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + rem;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            rem = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        while (l1 != NULL) {
            int sum = l1->val + rem;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            rem = sum / 10;
            l1 = l1->next;
            temp = temp->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + rem;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            rem = sum / 10;
            l2 = l2->next;
            temp = temp->next;
        }
        if (rem) {
            ListNode* newNode = new ListNode(rem);
            temp->next = newNode;
        }
        return res->next;
    }
};

// Approach 2 : Merge with smartness (lesser code)
// TC is O(n) and SC is O(1)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1, *curr2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;

        while (curr1 || curr2) {
            int dig1 = curr1 ? curr1->val : 0;
            int dig2 = curr2 ? curr2->val : 0;
            curr1 = curr1 ? curr1->next : NULL;
            curr2 = curr2 ? curr2->next : NULL;

            int sum = dig1 + dig2 + carry;
            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        temp->next = carry ? new ListNode(carry) : NULL;

        return dummy->next;
    }
};