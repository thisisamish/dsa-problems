// Written By - Amish Verma (@thisisamish)
// Approach 1 : Using stacks
// TC is O(n) and SC is O(n)

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
private:
    int findLength(ListNode* l) {
        ListNode* slow = l, *fast = l;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = findLength(l1);
        int len2 = findLength(l2);
        ListNode* list1, *list2;
        if (len1 > len2) {
            list1 = l1;
            list2 = l2;
        } else {
            list1 = l2;
            list2 = l1;
        }

        int diff = abs(len1 - len2);
        stack<int> sums;
        while (diff--) {
            sums.push(list1->val);
            list1 = list1->next;
        }
        while (list1) {
            sums.push(list1->val + list2->val);
            list1 = list1->next;
            list2 = list2->next;
        }

        int carry = 0;
        stack<int> res;
        while(!sums.empty()) {
            int toAdd = sums.top() + carry;
            sums.pop();
            res.push(toAdd % 10);
            carry = toAdd / 10;
        }
        if (carry) {
            res.push(carry);
        }

        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        while(!res.empty()) {
            ListNode* newNode = new ListNode(res.top());
            res.pop();
            dummy->next = newNode;
            dummy = dummy->next;
        }

        return head->next;
    }
};