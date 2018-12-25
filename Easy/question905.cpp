class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> end;
        if(not A.size()) return A;
        for(auto it = --A.end(); it >= A.begin(); it--){
            if ((*it) % 2 == 0){
                end.insert(end.begin(), *it);
            } else {
                end.push_back(*it);
            }
        }
        return end;
    }
};

// Much Slower Deque Implementation:
#include <deque>
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        deque<int> end;
        if(not A.size()) return A;
        
        for(auto it = --A.end(); it >= A.begin(); it--){
            if ((*it)%2 == 0){
                end.push_front(*it);
            } else {
                end.push_back(*it);
            }
        }
        vector<int> ans;
        for(auto it = end.begin(); it != end.end(); it++){
            ans.push_back(*it);
        }
        return ans;
        
    }
};