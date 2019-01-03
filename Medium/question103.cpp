class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        result.push_back(vector<int>(1,root->val));
        queue<TreeNode*> parents;
        parents.push(root);
        stack<TreeNode*> children;
        bool rtol = true;
        for(;;){
            vector<int> v;
            while(!parents.empty()){
                TreeNode* tmp = parents.front();
                if (rtol){
                    if(tmp->right) {
                        v.push_back(tmp->right->val);
                        children.push(tmp->right);
                    }
                    if (tmp->left) {
                        v.push_back(tmp->left->val);
                        children.push(tmp->left);
                    }
                } else {
                    if (tmp->left) {
                        v.push_back(tmp->left->val);
                        children.push(tmp->left);
                    }
                    if(tmp->right) {
                        v.push_back(tmp->right->val);
                        children.push(tmp->right);
                    }
                }
                parents.pop();
            }
            if (v.size()) result.push_back(v);
            rtol = !rtol;
            if (children.empty()) break;
            while(!children.empty()){
                parents.push(children.top());
                children.pop();
            }
                
        }
        return result;
    }
};