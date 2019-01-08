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

// Iterative:
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node* > myStack;
        if(root)
            myStack.push(root);
        
        while( !myStack.empty() ) {
            Node * cur = static_cast<Node*>(myStack.top());
            myStack.pop();
            ans.push_back(cur->val);
            
            if (cur->children.size() == 0)
                continue;
            
            vector<Node *> childs = cur->children;
            std::reverse(childs.begin(), childs.end());
            for (auto c: childs)
                myStack.push(c);

        }

        return ans;
    }
};