class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        auto root = new TreeNode(preorder.front());
        preorder.erase(preorder.begin());
        for (auto i : preorder)
            insert(root, i);
        return root;
    }
    
    void insert(TreeNode* root, int cur) {
        if (root->val > cur) {
            if (root->left)
                insert(root->left, cur);
            else
                root->left = new TreeNode(cur);
        }
        else if (root->val < cur) {
            if (root->right)
                insert(root->right, cur);
            else
                root->right = new TreeNode(cur);
        }
    }
};

auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();