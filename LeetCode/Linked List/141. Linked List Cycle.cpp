// Written By - Amish Verma (@thisisamish)
// Approach 1 : Using hashset
// TC is O(n), SC is O(n)

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
        if (head == NULL) return false;

        unordered_set<ListNode*> s;
        ListNode* curr = head;

        while (curr) {
            if (s.find(curr) == s.end()) {
                s.insert(curr);
            } else {
                return true;
            }
            curr = curr->next;
        }

        return false;
    }
};

// Approach 2 : Using slow and fast pointers
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;

        ListNode* slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        
        return false;
    }
};