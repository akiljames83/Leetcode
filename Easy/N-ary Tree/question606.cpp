// Correct Implementation:
class Solution {
public:
    string pot(TreeNode *node){
        return to_string(node->val) + 
        	((node->left) ? ("(" + pot(node->left) + ")") : ((node->right) ? "()" : "")) + 
        	((node->right) ? ("(" + pot(node->right) + ")") : "");  
    }
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string res = pot(t);
        return res;
    }
}; 

// No helper function implementation
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) 
            return "";
        return to_string(t->val) + 
            ((t->left) ? ("(" + tree2str(t->left) + ")") : ((t->right) ? "()" : "")) + 
            ((t->right) ? ("(" + tree2str(t->right) + ")") : "");
    }
};