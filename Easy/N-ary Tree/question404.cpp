class Solution {
public:
    void lsum(TreeNode* root, int & sum, bool isLeft){
        if (!root) return;
        if (!root->left and !root->right and isLeft)
            sum += root->val;
        else {
            lsum(root->left, sum, true);
            lsum(root->right, sum, false);
        }
            
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum{0};
        if (!root) 
            return sum;
        lsum(root->left, sum, true);
        lsum(root->right, sum, false);
        return sum;
    }
};