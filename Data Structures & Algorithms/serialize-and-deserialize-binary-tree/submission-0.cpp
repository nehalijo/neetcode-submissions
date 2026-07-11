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

class Codec {
public:
    int idx;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) {
            res += "N,";
            return res;
        }
        res += to_string(root->val) + ",";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> nodes;
        string cur;
        for (char c: data) {
            if (c == ',') {
                nodes.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }
        idx = 0;
        return dfs(nodes);
    }

    TreeNode* dfs(vector<string>& nodes) {
        if(nodes[idx] == "N") {
            idx++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodes[idx]));
        idx++;
        root->left = dfs(nodes);
        root->right = dfs(nodes);
        return root;
    }
};
