// Brute force Approach
class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size() - 1;
        while(front < back){
            if (s[front++] != s[back--])
                return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count{};
        for (int i = 0; i < s.size(); i++){
            for (int j = i; j < s.size(); j++) {
                if (isPalindrome(s.substr(i,j-i+1)))
                    count++;
            }
        }
        return count;
    }
};