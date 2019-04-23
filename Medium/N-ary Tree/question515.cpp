/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res = {};
        int next_row{}, this_row{1};
        int val = INT_MIN;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (q.size()) {
            auto cur = q.front();
            q.pop();
            val = max(cur->val, val);
            this_row--;
            if (cur->left){
                next_row++;
                q.push(cur->left);
            }
            if (cur->right) {
                next_row++;
                q.push(cur->right);
            }
            if (this_row == 0) {
                res.push_back(val);
                val = INT_MIN;
                this_row = next_row;
                next_row = 0;
            }
        }
        return res;
    }
};