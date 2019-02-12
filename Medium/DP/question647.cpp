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

// Build up approach:
class Solution {
public:
    int countSubstrings(string s) {
        int count{s.size()};
        // build up approach
        for (int i = 0; i != s.size(); i++) {
            int l = i;
            int r = i + 1;
            while (l >= 0 and r != s.size() and s[l--] == s[r++])
                count++;
            l = i - 1;
            r = i + 1;
            while (l >= 0 and r != s.size() and s[l--] == s[r++])
                count++;
        }
        return count;
    }
};