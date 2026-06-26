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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node) {
            while(node) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            k--;
            if (k == 0) return node->val;
            node = node->right;
        }
        return -1;
    }

};
