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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        // find n
        int n = 0;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            while (curr != nullptr) {
                curr = curr->next;
                n++;
            }
        }
        // until there are no more nodes to visit, check each node in each list to find the smallest
        ListNode* curr = dummy;
        for (int i = 0; i < n; i++) {
            // keep track of min value, and list that had the min value
            int minVal = INT_MAX;
            int listNum;
            for (int j = 0; j < lists.size(); j++) {
                ListNode* head = lists[j];
                if (head == nullptr) continue;
                if (head->val < minVal) {
                    minVal = head->val;
                    listNum = j;
                }
            }
            // add min value to dummy
            curr->next = lists[listNum];
            curr = curr->next;
            // move min value node to next node
            lists[listNum] = lists[listNum]->next;
        }
        return dummy->next;
    }
};
