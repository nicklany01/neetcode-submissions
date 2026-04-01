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
        int carry = 0;
        ListNode* result = l1;
        ListNode* last;
        while (l1 != nullptr || l2 != nullptr) {
            l1->val += carry + (l2 ? l2->val : 0);
            carry = l1->val / 10;
            l1->val %= 10;
            if (l1->next == nullptr) {
                last = l1;
                if (!l2) {
                    break;
                }
                swap(l1->next, l2->next);
            }
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        if (carry) {
            last->next = new ListNode(1);
        }
        return result;
    }
};
