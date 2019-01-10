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

// Better Solution: O(N) Time; O(1) space
class Solution {
public:
    void iot(TreeNode * node, int &mini, int& prev){
        if (!node) 
            return;
        
        if (node->left)
            iot(node->left, mini, prev);
        
        if (prev > 0)
            if (node->val - prev < mini)
                mini = node->val - prev;
        
        prev = node->val;
        
        if (node->right)
            iot(node->right, mini, prev);
            
    }
    
    int minDiffInBST(TreeNode* root) {
        int mini{INT_MAX}, prev{-1};
        iot(root, mini, prev);
        return mini;
    }
};