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
    bool isBalanced(TreeNode* root) {
        // post order traversal
        unordered_map<TreeNode*, int> heights;
        stack<TreeNode*> s;
        if (root == nullptr) return true;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            // if left node exists and hasnt been checked
            if (node->left != nullptr && !heights.contains(node->left)) {
                s.push(node->left);
            } else if (node->right != nullptr && !heights.contains(node->right)) {
                s.push(node->right);
            } else {
                int lHeight = heights[node->left];
                int rHeight = heights[node->right];
                heights[node] = 1 + max(lHeight, rHeight);
                cout << "lHeight: " << lHeight << ", rHeight: " << rHeight << "\n";
                if (abs(lHeight - rHeight) > 1) {
                    return false;
                }
                s.pop();
            }
        }
        return true;
    }
};
