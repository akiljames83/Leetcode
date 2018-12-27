class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        queue<int>veven;
        queue<int>vodd;
        vector<int>ans;
        for (auto i: A){
            if (i % 2) 
                vodd.push(i);
            else 
                veven.push(i);
        }
        bool even = true;
        for (int i = 0; i < A.size(); i++) {
            if (even) {
                ans.push_back(static_cast<int>(veven.front()));
                veven.pop();
            }
            else {
                ans.push_back(static_cast<int>(vodd.front()));
                vodd.pop();
            }
            even = !even;
        }
        return ans;
    }
    
};