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
    void reverse(ListNode* start, ListNode* end) {
        ListNode* prev = start;
        ListNode* curr = start->next;
        while (curr != end) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* head1 = dummy;
        ListNode* head2 = dummy->next;
        ListNode* curr = head2;
        while (curr != nullptr) {
            // increment by k-1
            for (int i = 1; i < k; i++) {
                curr = curr->next;
                if (curr == nullptr) return dummy->next;
            }
            ListNode* next = curr->next;
            // reverse from head2 to curr
            reverse(head2, next);
            head1->next = curr;
            head2->next = next;
            curr = next;
            head1 = head2;
            head2 = curr;
        }
        return dummy->next;
    }
};
