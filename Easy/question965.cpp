// Question965
class Solution {
public:
    bool check(TreeNode*node , int val){
        if (!node) return true;
        if (node->val != val) return false;
        return (check(node->left, val) and check(node->right, val));
    }
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        return check(root, root->val);
    }
};