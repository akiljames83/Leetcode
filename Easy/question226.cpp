class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> children;
        if (!root) return root;
        children.push(root);
        while(!children.empty()){
            int size = children.size();
            for (int i = 0; i < size; i++){
                TreeNode* tmp = children.front();
                // swap
                TreeNode* right = tmp->right;
                tmp->right = tmp->left;
                tmp->left = right;
                // push
                if (tmp->left) children.push(tmp->left);
                if (tmp->right) children.push(tmp->right);
                // pop
                children.pop();
            }
        }
        return root;
    }
};

// Recursive Solution
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        auto tmp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(tmp);
        return root;
    }
};