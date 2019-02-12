class BSTIterator {
private:
    TreeNode* top;
public:
    
    BSTIterator(TreeNode* root) {
        this->top = root;
    }
    
    /** @return the next smallest number */
    int next() {
        auto cur = this->top;
        auto prev = cur;
        
        if (!cur->left) {
            this->top = cur->right;
            return cur->val;
        }
        
        while (cur->left) {
            prev = cur;
            cur = cur->left;
        }
        if (!cur->right){
            prev->left = NULL;
        } else {
            prev->left = cur->right;
        }
        return cur->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return this->top != NULL;
    }
};