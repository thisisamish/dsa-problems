// Approach 1 : Iterative solution
// TC is O(n), SC is O(n)

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr != NULL and curr->next != NULL) {
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;
            second->next = curr;
            curr->next = nextPair;
            prev->next = second;
            prev = curr;
            curr = nextPair;
        }
        return dummy->next;
    }
};

// Approach 2 : Recursive solution
// TC is O(n), SC is O(n) (stack space)

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
    ListNode* swapper(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* nextHead = head->next->next;
        ListNode* newHead = head->next;
        head->next->next = head;
        head->next = swapper(nextHead);
        return newHead;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        return swapper(head);
    }
};