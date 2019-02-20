class Solution {
public:
    void dandp(TreeNode * root, int val, int depth, int & vp, int & vd) {
        //cout << val << endl;
        if (!root)
            return;
        if (root->val == val)
            return;
            
        if (root->right) {
            if (root->right->val == val) {
                vd = depth + 1;
                vp = root->val;
                return;
            } else {
                dandp(root->right, val, depth + 1, vp, vd);
            }
        } 
        if (root->left){
            if (root->left->val == val) {
                vd = depth + 1;
                vp = root->val;
                return;
            } else {
                dandp(root->left, val, depth + 1, vp, vd);
            }
        } 
            
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if (x == y)
            return true;
        int px{INT_MAX}, py{INT_MAX}, dx{0}, dy{0};
        dandp(root, x, 0, px, dx);
        dandp(root, y, 0, py, dy);
        if (dx == dy and px != py)
            return true;
        return false;
    }
};