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
        ListNode dummy(0, head);
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        int i = 0;
        while (first != nullptr) {
            first = first->next;
            if (i++ > n) {
                second = second->next;
            }
        }
        
        second->next = second->next->next;
        return dummy.next;
    }
};
