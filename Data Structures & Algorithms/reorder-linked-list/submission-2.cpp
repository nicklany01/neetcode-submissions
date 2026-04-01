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
        ListNode* l1 = head;
        ListNode* l2 = l1;
        // get size of list
        int n = 0;
        for (; head != nullptr; n++) {
            head = head->next;
        }
        // get second half
        for (int i = 0; i < (n - 1)/2; i++) {
            l2 = l2->next;
        }
        // reverse l2
        ListNode* prev = nullptr;
        ListNode* curr = l2->next;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        l2->next = nullptr;
        l2 = prev;
        // merge l1 and l2
        for (int i = 0; i < n; i++) {
            ListNode* temp;
            if (i % 2 == 0) {
                temp = l1->next;
                l1->next = l2;
                l1 = temp;
            } else {
                temp = l2->next;
                l2->next = l1;
                l2 = temp;
            }
        }
    }
};
