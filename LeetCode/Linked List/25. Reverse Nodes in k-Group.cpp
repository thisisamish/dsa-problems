// Written By - Amish Verma (@thisisamish)
// TC is O(n) and SC is O(k)

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
        ListNode* slow = head, *fast = head;
        int count = 0;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }
        if (fast == NULL) return count * 2;
        return count * 2 + 1;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l = lengthOfLL(head);

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* res = dummy;
        ListNode* curr = head;

        while (l >= k) {
            stack<ListNode*> s;
            for (int i = 0; i < k; i++) {
                s.push(curr);
                curr = curr->next;
            }
            while(!s.empty()) {
                ListNode* node = s.top();
                s.pop();
                dummy->next = node;
                dummy = dummy->next;
            }
            l -= k;
        }

        dummy->next = curr;

        return res->next;
    }
};