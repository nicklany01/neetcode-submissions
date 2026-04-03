/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptrptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptrptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool checkTree(TreeNode* r1, TreeNode* r2) {
        // base cases
        if (r1 != nullptr) cout << "r1: " << r1->val << endl;
        if (r2 != nullptr) cout << "r2: " << r2->val << endl;
        if (r1 == nullptr && r2 == nullptr) return true; // subtree has ended
        if (r1 == nullptr || r2 == nullptr || r1->val != r2->val) return false; // main tree ended but subtree hasnt
        // check left and right side of trees
        return checkTree(r1->left, r2->left) && checkTree(r1->right, r2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) continue;
            if (node->val == subRoot->val && checkTree(node, subRoot)) return true; 
            q.push(node->left);
            q.push(node->right);
        }
        return false;
    }
};
