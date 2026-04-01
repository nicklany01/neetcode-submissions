/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // bfs traversal checking the values are always the same, size is the same on each row too
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(q);
        q2.push(p);
        while (!q1.empty() && !q2.empty()) {
            int size1 = q1.size();
            int size2 = q2.size();
            // mismatch in structure
            if (size1 != size2) {
                return false;
            }
            for (int i = 0; i < size1; i++) {
                TreeNode* node1 = q1.front();
                TreeNode* node2 = q2.front();
                if ((node1 == nullptr || node2 == nullptr) && node1 != node2) {
                    return false;
                } 
                if (node1 != nullptr) {
                    if (node1->val != node2->val) {
                        return false;
                    }
                    q1.push(node1->left);
                    q1.push(node1->right);
                    q2.push(node2->left);
                    q2.push(node2->right);
                }
                q1.pop();
                q2.pop();
            }
        }
        // if the queues arent both empty, there is a mismatch
        if (!(q1.empty() && q2.empty())) {
            return false;
        }
        return true;
    }
};
