// Written By - Amish Verma (@thisisamish)
// Approach 1 : Naive approach
// TC is O(n), SC is O(1)

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
    int lengthOfLL(ListNode* head) {
        ListNode *slow = head, *fast = head;
        int count = 0;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }
        if (!fast) return count * 2;
        return count * 2 + 1;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = lengthOfLL(head);
        ListNode* curr = head;
        int check = l - n - 1;

        if (n == l) return head->next;

        while (check--) curr = curr->next;
        curr->next = curr->next->next;

        return head;
    }
};

// Approach 2 : Slightly better approach
// TC is O(n), SC is O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (n > 0) {
            fast = fast->next;
            n--;
        }

        if (fast == NULL) {
            return head->next;
        }

        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};