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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        if (root)
            reverseOrder(root, &sum);
        return root;
    }
    
    void reverseOrder(TreeNode* root, int* sum) {
        // check right
        if (root->right)
            reverseOrder(root->right, sum);
        // current
        int tmp = root->val;
        root->val += *sum;
        *sum += tmp;
        // check left
        if (root->left)
            reverseOrder(root->left, sum);
    }
};

auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();