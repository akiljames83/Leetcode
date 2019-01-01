// Question 897
class Solution {
public:
    void iot(TreeNode* node, vector<int>& vec) {
        if (!node) 
            return;
        iot(node->left, vec);
        vec.push_back(node->val);
        iot(node->right, vec);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vec;
        iot(root, vec);

        TreeNode *begin = new TreeNode(vec[0]);
        TreeNode *node = begin;
        for (int i = 1; i < vec.size(); i++) {
            node->right = new TreeNode(vec[i]);
            node = node->right;
        }
        return begin;
    }
};