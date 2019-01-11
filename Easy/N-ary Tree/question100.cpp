class Solution {
public:
    void iot(TreeNode * n, vector<int>& v){
        if (!n)
            return;
        if (n->left)
            iot(n->left, v);
        v.emplace_back(n->val);
        if (n->right){
            n->right->val += 1;
            iot(n->right, v);
        }
            
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pv;
        vector<int> qv;
        iot(p, pv);
        iot(q, qv);
        if (pv.size() != qv.size()) return false;
        for (int i  = 0; i < pv.size(); i++)
            if (pv[i] != qv[i])
                return false;
        return true;
    }
};