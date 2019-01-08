class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root) return result;
        queue<TreeNode*> parent, children;
        parent.push(root);
        for(;;){
            double avg{0};
            int count{0};
            while(!parent.empty()){
                //cout << avg << " + " << parent.front()->val << " = ";
                avg += parent.front()->val;
                count++;
                //cout << avg << " Count: "<< count<< endl;
                
                if (parent.front()->left)
                    children.push(parent.front()->left);
                if (parent.front()->right)
                    children.push(parent.front()->right);
                parent.pop();
            }
            avg /= count;
            result.push_back(avg);
            if (children.empty()) break;
            while(!children.empty()){
                parent.push(children.front());
                children.pop();
            }
        }
        return result;
    }
};