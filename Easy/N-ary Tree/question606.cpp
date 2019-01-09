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
