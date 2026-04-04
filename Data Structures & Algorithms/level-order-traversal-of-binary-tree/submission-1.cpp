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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> q; // level it's on, node
        vector<vector<int>> result;
        q.push({0,root});
        while (!q.empty()) {
            int level = q.front().first;
            TreeNode* node = q.front().second;
            q.pop();
            if (node == nullptr) continue;
            // if the result list needs another layer
            if (level == result.size()) result.push_back(vector<int>());
            q.push({level + 1, node->left});
            q.push({level + 1, node->right});
            result[level].push_back(node->val);
        }
        return result;
    }
};
