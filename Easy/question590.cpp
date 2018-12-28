// Recursive Approach:
class Solution {
public:
    void poh(Node* node, vector<int> &vec){
        if (node->children.size() == 0) {
            vec.push_back(node->val);
            return;
        }
        for (auto child: node->children)
            poh(child,vec);
        
        vec.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        poh(root, ans);
        return ans;
    }
};

// Iterative Approach: