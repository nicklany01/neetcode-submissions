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
private:
    vector<int> serialiseTree(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node == nullptr) {
                result.push_back(-101);
                continue;
            }
            result.push_back(node->val);
            s.push(node->right);
            s.push(node->left);
        }
        return result;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;
        // serialise trees
        vector<int> tree1 = serialiseTree(root);
        vector<int> tree2 = serialiseTree(subRoot);
        // knuth-morris-pratt string search
        int n = tree1.size();
        int m = tree2.size();
        // calculate lps array
        vector<int> lps(m,0);
        int len = 0; // length of previous longest prefix suffix
        int i, j;
        i = 1;
        while (i < m) {
            // prefix from 0..len-1 is suffix from i-len..i-1
            // next char matches, extend the lps
            if (tree2[i] == tree2[len]) {
                lps[i] = ++len;
                i++;
            // next char doesnt match, but we can go back and check a shorter prefix suffix exists and check that too
            } else if (len > 0) {
                len = lps[len-1];
            // there is no prefix suffix, reset
            } else {
                lps[i++] = 0;
            }
        }
        // go through loop, if we hit a mismatch we can check again with the j = lps
        i = 0;
        j = 0;
        while (i < n) {
            if (tree1[i] == tree2[j]) {
                i++;
                j++;
            } else if (j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
            if (j == m) return true;
        }
        return false;
    }
};
