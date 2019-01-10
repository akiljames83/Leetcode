class Solution {
public:
    void iot(TreeNode * node, vector<int>& vals){
        if (!node) return;
        // Root left
        if (node->left)
            iot(node->left, vals);
        // Current
        vals.emplace_back(node->val);
        // Root right
        if (node->right)
            iot(node->right, vals);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> vals;
        iot(root, vals);
        int min{INT_MAX};
        for (int i = 1; i < vals.size(); i++){
            if (vals[i] - vals[i-1] < min)
                min = vals[i] - vals[i-1];
        }
        return min;
    }
};