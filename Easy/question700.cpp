auto __=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
     TreeNode* search(TreeNode* root, int val){
        if (root == NULL) 
            return nullptr;
        if (root->val == val)
            return root;
        if (root->left == NULL and root->right == NULL) 
            return nullptr;
        TreeNode* right = search(root->right, val);
        return right ? right : search(root->left, val); 
            
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) 
            return root;
        return search(root, val);
    }
};