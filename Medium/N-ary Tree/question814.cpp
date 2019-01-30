class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root)
            return root;
        if (root->left) {
            if (!root->left->left and !root->left->right and !root->left->val)
                root->left = nullptr;
            else {
                root->left = pruneTree(root->left);
                if (!root->left->left and !root->left->right and !root->left->val)
                    root->left = nullptr;
            }
        }
            
        if (root->right) {
            if (!root->right->left and !root->right->right and !root->right->val)
                root->right = nullptr;
            else {
                root->right = pruneTree(root->right);
                if (!root->right->left and !root->right->right and !root->right->val)
                    root->right = nullptr;
            }
        }
        return root;
                
    }
};