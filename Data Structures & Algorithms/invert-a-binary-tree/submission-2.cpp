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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q; // breadth first search, although it doesnt matter for this algorithm
        q.push(root);
        while (!q.empty()) {
            if (q.front() == nullptr) {
                q.pop();
                continue;
            }
            TreeNode* node = q.front();
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            q.pop();
        }
        return root;
    }
};
