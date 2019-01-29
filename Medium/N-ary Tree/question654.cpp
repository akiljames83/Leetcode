class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
    
    TreeNode * construct(vector<int>& nums, int L, int R) {
        int pos = L;
        int mval = nums[L];
        for (int i = L + 1; i < R; i++){
            if (nums[i] > mval){
                mval = nums[i];
                pos = i;
            }
        }
        
        TreeNode *top = new TreeNode(nums[pos]);
        
        top->left = (pos == L) ? nullptr : construct(nums, L, pos);
        top->right = (pos == R - 1) ? nullptr : construct(nums, pos+1, R);
        
        return top;
    }
};