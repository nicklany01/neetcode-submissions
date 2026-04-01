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
    bool hasCycle(ListNode* head) {
        ListNode unreachable;
        ListNode* curr = head;
        if (head == nullptr) return false;
        while (curr->next != nullptr) {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = &unreachable;
            if (curr == &unreachable) {
                return true;
            }
        }
        return false;
    }
};
