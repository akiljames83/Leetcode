class Solution {
public:
    // check height
    int height(TreeNode * node, int & dif){
        if (!node)
            return 0;
        int left = height(node->left, dif);
        int right = height(node->right, dif);
        if (left + right > dif)
            dif = left + right;
            
        return 1 + max(left, right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int dif = 0;
        int ret = height(root->left, dif) + height(root->right, dif);
        if (dif > ret)
            ret = dif;
            
        return ret;
    }
};