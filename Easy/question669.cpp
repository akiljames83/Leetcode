// Iterative Approach
class Solution {
public:
    void trimLeft(TreeNode* root, int L){
        TreeNode* node = root;
        for(;;){
            if (!node) return;
            if (node->val == L ){
                node->left = nullptr;
                return;
            }
            if (node->left){
                if (node->left->val == L){
                    node->left->left = nullptr;
                    return;
                }
                if (node->left->val > L){
                    node = node->left;
                    continue;
                }
                if (node->left->val < L ){
                    if (node->left->right){
                        if (node->left->right->val >= L or node->left->right->right){
                            node->left = node->left->right;
                            continue;
                        }
                        node->left = nullptr;
                        return;
                    }
                    node->left = nullptr;
                    return;
                }
            }
            return;
            
        }
            
    }
    void trimRight(TreeNode* root, int R){
        TreeNode* node = root;
        for(;;){
            if (!node) return;
            if (node->val == R ){
                node->right = nullptr;
                return;
            }
            if (node->right){
                if (node->right->val == R){
                    node->right->right = nullptr;
                    return;
                }
                if (node->right->val < R){
                    node = node->right;
                    continue;
                }
                if (node->right->val > R ){
                    if (node->right->left){
                        if (node->right->left->val <= R or node->right->left->left){
                            node->right = node->right->left;
                            continue;
                        }
                        node->right = nullptr;
                        return;
                    }
                    node->right = nullptr;
                    return;
                }
            }
            return;
            
        }
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) 
            return NULL;
        if (L == R) 
            return new TreeNode(L);
        
        while(root->val < L)
            root = root->right;
        trimLeft(root, L);
        
        while(root->val > R)
            root = root->left;
        trimRight(root, R);
        
        return root;
    }
};

// TODO: Recursive Approach!