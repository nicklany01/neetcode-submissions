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
    bool isValidBST(TreeNode* root) {
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push({{INT_MIN, INT_MAX}, root});
        while (!q.empty()) {
            int minVal = q.front().first.first;
            int maxVal = q.front().first.second;
            TreeNode* node = q.front().second;
            q.pop();
            if (node == nullptr) continue;
            if (node->val <= minVal || node->val >= maxVal) return false;
            q.push({{minVal, node->val}, node->left});
            q.push({{node->val, maxVal}, node->right});
        }
        return true;
    }
};
