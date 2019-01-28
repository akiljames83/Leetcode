class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0)
            return 0;
        if(s.length() == 1 and s[0] == ' ')
            return 0;
        int count = 0;
        int back{s.length()-1};
        if (s[back] == ' '){
            while(back >= 0 and s[back] == ' ')
                back--;
        }
        while (back >= 0) {
            if (s[back--] != ' ')
                count++;
            else 
                return count;
        }
        return count;
    }
};