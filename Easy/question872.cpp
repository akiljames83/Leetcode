class Solution {
public:
    void leafs(TreeNode* node, vector<int> &leaves){
        if (node == NULL) return;
        if (!node->right and !node->left){
            leaves.push_back(node->val);
            return;
        }
        if (node->left) leafs(node->left, leaves);
        if (node->right) leafs(node->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        leafs(root1, tree1);
        leafs(root2, tree2);
        if (tree1.size() != tree2.size()) return false;
        for (int i = 0; i < tree1.size(); i++){
            if (tree1[i] != tree2[i]) return false;
        }
        return true;
    }
};