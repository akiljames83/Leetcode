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
    bool isSymmetric(TreeNode* root) {
       if (!root)
           return true;
        if (!root->left)
            return (!root->right) ? true : false;
        if (!root->right)
            return false;
        if (root->left->val != root->right->val) return false;
        vector<int> front;
        vector<int> back;
        iot(root->left, front);
        iot(root->right, back);
        reverse(back.begin(), back.end());
        if (front.size() != back.size()) return false;
        for (int i = 0; i < front.size(); i++) {
            if (front[i] != back[i])
                return false;
        }
        return true;
                
    }
    void iot(TreeNode * root, vector<int> & s) {
        if (!root) {
            s.push_back(0);
            return;
        }
        iot(root->left, s);
        s.push_back(root->val);
        iot(root->right, s);
    }
};

/*
[1,2,2,3,4,4,3]
[1,2,3,3,null,2,null]
[1,2,2,null,3,null,3]
*/