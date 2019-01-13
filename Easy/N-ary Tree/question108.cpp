class Solution {
public:
    TreeNode * makeBST(vector<int>& nums, int low, int high){
        if (low > high) 
            return NULL;
        int mid = (high + low)/2;
        TreeNode * cur = new TreeNode(nums[mid]);
        cur->left = makeBST(nums, low, mid - 1);
        cur->right = makeBST(nums, mid + 1, high);
        return cur;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (!nums.size()) 
            return NULL;
        int mid = (nums.size() - 1)/2;
        TreeNode * head = new TreeNode(nums[mid]);
        head->left = makeBST(nums, 0, mid - 1);
        head->right = makeBST(nums, mid + 1, nums.size() - 1);
        return head;
    }
};