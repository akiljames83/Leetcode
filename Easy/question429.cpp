class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<Node*>parent, children;
        parent.push(root);
        for(;;) {
            vector<int>v;
            while(!parent.empty()){
                v.push_back(parent.front()->val);
                for (auto c : parent.front()->children)
                    children.push(c);
                parent.pop();
            }
            result.push_back(v);
            if (children.empty()) break;
            while(!children.empty()){
                parent.push(children.front());
                children.pop();
            }
        }
        return result;
    }
};