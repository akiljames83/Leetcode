class Solution {
public:
    vector<int> diStringMatch(string S) {
        int top{S.length()};
        int bottom{};
        vector<int> ans;
        for(auto ch: S){
            if (ch == 'I') ans.push_back(bottom++);
            else ans.push_back(top--);
        }
        if (top == bottom) ans.push_back(top);
        return ans;
    }
};