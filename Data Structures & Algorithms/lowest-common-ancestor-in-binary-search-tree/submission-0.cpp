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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* y) {
        // tracks whether this is the parent of either x or y
        unordered_map<TreeNode*, bool> parent;
        // reverse level order traversal
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        s.push(root);
        // visit all the nodes
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) continue;
            q.push(node->left);
            q.push(node->right);
            s.push(node->left);
            s.push(node->right);
        }
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node == nullptr) continue;
            // cout << "node: " << node->val << endl;
            if (node == x || node == y) {
                parent[node] = true;
            }
            // if both the children are parents, this is the lowest common ancestor
            if (node != nullptr && parent[node->left] && parent[node->right]) {
                return node;
            // if the children have been marked as parents to either x or y, mark this node too
            } else if (node != nullptr && (parent[node->left] || parent[node->right])) {
                if (parent[node]) return node;
                parent[node] = true;
            }
        }
        return root;
    }
};
