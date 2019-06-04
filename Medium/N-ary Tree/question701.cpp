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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode * prev = nullptr;
        auto cur = root;
        while(prev != cur){
            prev = cur;
            if (cur->val > val) {
                // go to left
                if (cur->left) cur = cur->left;
                else cur->left = new TreeNode(val);
            } else {
                // go right
                if (cur->right) cur = cur->right;
                else cur->right = new TreeNode(val);
            }
        }
        return root;
    }
};
auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();