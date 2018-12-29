// Recursive Solution: Question 559
class Solution {
public:
    int max(Node* root, int tot){
        if (root == NULL) return tot;
        vector <Node*> childs = root->children;
        if (childs.size() == 0) return tot + 1;
        int max_depth{0};
        for (auto c: childs){
            int cur = max(c, tot+1);
            max_depth = max_depth > cur ? max_depth : cur;
        }
        return max_depth;
    }
    int maxDepth(Node* root) {
        
        return max(root, 0);
    }
};

// Cleaner Solution
int maxDepth(Node* root) {
        if(!root) return 0;
        int depth{0};
        for (Node * c : root->children){
            depth = std::max(depth, maxDepth(c));
        }
        return depth + 1;
}