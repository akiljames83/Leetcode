class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        string num;
        while(x){
            int n = x % 10;
            num += static_cast<int>('a' + n);
            x /= 10;
        }
        int f{0};
        int b{num.size() - 1};
        while(f < b) {
            if (num[f++] != num[b--])
                return false;
        }
        return true;
    }
};