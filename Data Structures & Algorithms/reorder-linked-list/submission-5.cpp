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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* l1 = head;
        ListNode* l2 = l1;
        // fast and slow pointer method to find the middle
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        l2 = slow->next;
        slow->next = nullptr;
        // reverse l2
        ListNode* prev = nullptr;
        ListNode* curr = l2;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        l2->next = nullptr;
        l2 = prev;
        // merge l1 and l2
        while (l2 != nullptr) {
            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;
            l1->next = l2;
            l2->next = temp1;
            l1 = temp1;
            l2 = temp2;
        }
    }
};
