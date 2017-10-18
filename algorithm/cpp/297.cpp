/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void serialize(TreeNode *root, stringstream& in) {
        if (root) {
            in << root->val << " ";
            serialize(root->left, in);
            serialize(root->right, in);
        } else {
            in << "# ";
        }
    }

    TreeNode *deserialize(stringstream& out) {
        string s;
        out >> s;
        if (s == "#") return 0;

        TreeNode *node = new TreeNode(stoi(s));
        node->left = deserialize(out);
        node->right = deserialize(out);
        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream in;
        serialize(root, in);
        return in.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream out(data);
        return deserialize(out);
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
