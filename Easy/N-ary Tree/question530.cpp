class Solution {
public:
    void pot(TreeNode * root, int & min ,int & prev) {
        if (!root)
            return;
        
        if (root->left)
            pot(root->left, min, prev);
        
        if (prev > -1 and root->val - prev < min)
            min = root->val - prev;
        
        prev = root->val;
        
        if (root->right)
            pot(root->right, min, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int min{INT_MAX}, prev{-1};
        pot(root, min, prev);
        return min;
    }
};