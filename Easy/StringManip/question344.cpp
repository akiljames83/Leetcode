class Solution {
public:
    string reverseString(string s) {
        std::reverse(s.begin(),s.end());
        return s;
    }
};

// Actual Solution
class Solution {
public:
    string reverseString(string s) {
        int begin{};
        int end{s.size() - 1};
        while(begin <= end){
            char tmp = s[begin];
            s[begin++] = s[end];
            s[end--] = tmp;
        }
        return s;
    }
};