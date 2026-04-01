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
    int diameterOfBinaryTree(TreeNode* root) {
        // post order traversal so that we can get the heights of the children before reaching the parent
        unordered_map<TreeNode*, int> heights;
        stack<TreeNode*> s;
        s.push(root);
        int maxD = 0;
        while (!s.empty()) {
            TreeNode* curr = s.top();
            // if the left child exists and hasn't already been searched
            if (curr->left && !heights.contains(curr->left)) {
                s.push(curr->left);
            } else if (curr->right && !heights.contains(curr->right)) {
                s.push(curr->right);
            // if the children have already been searched
            } else {
                s.pop();
                int leftH = heights[curr->left];
                int rightH = heights[curr->right];
                heights[curr] = 1 + max(leftH, rightH);
                maxD = max(maxD, leftH + rightH);
            }
        }
        return maxD;
    }
};
