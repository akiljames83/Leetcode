class Solution {
public:
    void constructor(vector<string>& res, TreeNode * node, string past) {
        if (!node->left and !node->right) {
            res.emplace_back(past);
            return;
        }  
        if (node->left)
            constructor(res, node->left, past + "->" + to_string(node->left->val));
        if (node->right)
            constructor(res, node->right, past + + "->" + to_string(node->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        constructor(res, root, to_string(root->val));
        return res;
    }
};