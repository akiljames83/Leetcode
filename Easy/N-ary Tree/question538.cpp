class Solution {
public:
    void pot(TreeNode* node, int & total){
        if (!node)
            return;
        if (node->right)
            pot(node->right, total);
        
        total += node->val;
        
        if (node->left)
            pot(node->left, total);
            
    }
    void iot(TreeNode* node, int & total){
        if (!node)
            return;
        
        if (node->left)
            iot(node->left, total);
            
        total -= node->val;
        node->val += total;
        
        if (node->right)
            iot(node->right, total);
    }
    TreeNode* convertBST(TreeNode* root) {
        int total{0};
        pot(root, total);
        iot(root, total);
        return root;
    }
};

// Better Solution: Iterating through the tree one time
class Solution {
public:
    void pot(TreeNode* node, int & total){
        if (!node)
            return;
        if (node->right)
            pot(node->right, total);
        
        int tmp = node->val;
        node->val += total;
        total += tmp;
        
        
        if (node->left)
            pot(node->left, total);
            
    }
    TreeNode* convertBST(TreeNode* root) {
        int total{0};
        pot(root, total);
        return root;
    }
};