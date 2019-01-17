class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        int num_nodes{1};
        int num_children{0};
        queue<TreeNode*> children;
        children.push(root);
        vector<int> temp_row;
        while(!children.empty()) {
            TreeNode * cur = children.front();
            children.pop();
            if (cur->left){
                num_children++;
                children.push(cur->left);
            }
            if (cur->right) {
                num_children++;
                children.push(cur->right);
            }
            temp_row.emplace_back(cur->val);
            num_nodes--;
            if (!num_nodes) {
                res.emplace_back(temp_row);
                num_nodes = num_children;
                num_children = 0;
                temp_row = {};
            }
        }
        
        if (temp_row.size())
            res.push_back(temp_row);
        std::reverse(res.begin(), res.end());
        return res;
        
    }
};