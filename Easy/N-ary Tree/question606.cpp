// Wrong Implementation
class Solution {
public:
    string pot(TreeNode *node, string str){
        if (!node) 
            return str;
        string tstr{""};
        if (node->right)
            str = pot(node->right, str);
        
        //tstr = "(" + to_string(node->val) + ")";
        tstr = to_string(node->val);
        
        if (node->left)
            str = pot(node->left, str);
        else
            if (node->right)
                str = "()" + str;
        
        return tstr + "(" + str + ")";
    }
    string tree2str(TreeNode* t) {
        string res = pot(t, "");
        return res;
    }
};