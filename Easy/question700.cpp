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

// Better Solution - Realizing it is a binary search tree and not just a binary tree
class Solution {
public:
     TreeNode* search(TreeNode* root, int val){
        if (root == NULL) 
            return nullptr;
        if (root->val == val)
            return root;
        if (root->left == NULL and root->right == NULL) 
            return nullptr;
        if (root->val > val) 
            return search(root->left, val);
        
        return search(root->right, val);
            
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) 
            return root;
        return search(root, val);
    }
};

// Iterative Solution:
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr) {
            if (root-> val == val)
                return root;
            if (root->val > val) {
                root = root->left;
                continue;
            }
            root = root->right;     
        }
        return nullptr;
    }
};