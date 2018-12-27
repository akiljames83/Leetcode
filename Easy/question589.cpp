class Solution {
public:
    void poh(Node* node, vector<int>& vec){
        vec.push_back(node->val);
        for (auto n: node->children)
            poh(n, vec);
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        if (root == NULL) return ans;
        ans.push_back(root->val);
        for (auto n: root->children)
            poh(n, ans);
        return ans;
    }
};