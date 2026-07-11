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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsS(root, res);
        return join(res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens = split(data);
        int idx = 0;
        return dfsD(tokens, idx);
    }

private:
    void dfsS(TreeNode* root, vector<string>& res) {
        if(!root) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(root->val));
        dfsS(root->left, res);
        dfsS(root->right, res);
    }

    TreeNode* dfsD(vector<string>& tokens, int& idx) {
        if (tokens[idx] == "N") {
            idx++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(tokens[idx]));
        idx++;
        node->left = dfsD(tokens, idx);
        node->right = dfsD(tokens, idx);
        return node;
    }

    string join(const vector<string>& tokens) {
        string res;
        for (const string& s: tokens) {
            res += s + ",";
        }
        return res;
    }


    vector<string> split(const string& data) {
        vector<string> tokens;
        string cur;
        for (char c: data) {
            if (c == ',') {
                tokens.push_back(cur);
                cur.clear();
            }
            else {
                cur += c;
            }
        }
        return tokens;
    }
};
