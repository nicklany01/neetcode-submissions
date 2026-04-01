/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* oldCurr = head;
        Node* newHead = new Node(head->val);
        Node* curr = newHead;
        unordered_map<Node*,Node*> link;
        int count = 0;
        link[oldCurr] = curr;
        while (oldCurr->next != nullptr)  {
            oldCurr = oldCurr->next;
            curr->next = new Node(oldCurr->val);
            curr = curr->next;
            link[oldCurr] = curr;
        }
        curr->next = nullptr;
        oldCurr = head;
        while (oldCurr != nullptr)  {
            curr = link[oldCurr];
            curr->random = link[oldCurr->random];
            oldCurr = oldCurr->next;
        }
        return newHead;
    }
};
