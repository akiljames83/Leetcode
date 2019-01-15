class Solution {
public:
    int sum(TreeNode* node){
        if (!node)
            return 0;
        return node->val + sum(node->left) + sum(node->right);
    }
    int findTilt(TreeNode* node) {
        if (!node) 
            return 0;
        return abs(sum(node->left) - sum(node->right)) + findTilt(node->right) + findTilt(node->left);
    }
};