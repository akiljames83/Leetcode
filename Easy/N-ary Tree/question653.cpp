class Solution {
public:
    bool FOUND = false;
    void iot(TreeNode* node, unordered_map<int, int>& map, int k){
        if (!node) return;
        if (node->left) 
            iot(node->left, map, k);
        if (map.find(k - node->val) != map.end()){
            FOUND = true;
            return;
        } else {
            map[node->val] = 0;
        }
        if (node->right)
            iot(node->right, map, k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> map;
        iot(root, map, k);
        return FOUND;
    }
};