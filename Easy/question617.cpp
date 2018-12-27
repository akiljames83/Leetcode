/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**************
 *            *
 * NOT SOLVED *
 *            *
 **************/

class Solution {
public:
    void merge(TreeNode* first, TreeNode* second){
        if (first == NULL and second == NULL) return;
        if (second == NULL) return;
        if (first == NULL) {
            first = new TreeNode(second->val);
            merge(first->left, second->left);
            merge(first->right, second->right);
            
        } else {
            first->val += second->val;
            merge(first->left, second->left);
            merge(first->right, second->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        merge(t1, t2);
        return t1;
    }
};