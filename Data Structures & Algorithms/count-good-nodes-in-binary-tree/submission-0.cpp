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
    int goodNodes(TreeNode* root) {
        stack<pair<int,TreeNode*>> s;
        s.push({root->val, root});
        int result = 0;
        while (!s.empty()) {
            int maxVal = s.top().first;
            TreeNode* node = s.top().second;
            s.pop();
            if (node == nullptr) continue;
            if (node->val >= maxVal) {
                result++;
            }
            maxVal = max(maxVal, node->val);
            s.push({maxVal, node->left});
            s.push({maxVal, node->right});
        }
        return result;
    }
};
