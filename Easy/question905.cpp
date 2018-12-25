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

// Cleaner version:
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(not A.size()) return A;
        vector<int> odd, even;

        for(auto it : A){
            if (it % 2 == 0){
                even.push_back(it);
            } else {
                odd.push_back(it);
            }
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};

// Best Version: Inplace and O(n) runtime
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(not A.size()) return A;
        auto front = A.begin();
        while(front != A.end() && *front % 2 == 0 ) front++;
        if (front == A.end()) return A;
        auto cur = front + 1;
        int curVal;
        for (; cur != A.end(); cur++){
            if( *cur % 2 == 0) {
                curVal = *cur;
                *cur = *front;
                *front = curVal;
                front++;
            }
        }
        return A;
    }
};