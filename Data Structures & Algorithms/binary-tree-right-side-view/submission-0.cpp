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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        q.push({0, root});
        vector<int> result;
        while (!q.empty()) {
            int level = q.front().first;
            TreeNode* node = q.front().second;
            q.pop();
            if (node == nullptr) continue;
            if (level == result.size()) result.push_back(node->val);
            q.push({level+1, node->right});
            q.push({level+1, node->left});
        }
        return result;
    }
};
