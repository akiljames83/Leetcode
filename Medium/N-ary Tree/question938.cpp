class Solution {
public:
    void iot(TreeNode * root, int & sum, int L, int R) {
        if (root->val >= L and root->val <= R)
            sum += root->val;
        if (root->left)
            iot(root->left, sum, L, R);
        if (root->right)
            iot(root->right, sum, L, R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum{0};
        if (!root)
            return 0;
        iot(root, sum, L, R);
        return sum;
    }
};