#define cap(c) ((c >= 'A') and (c <= 'Z'))
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (cap(word[0])){ // Two cases
            int count = 1;
            for (int i = 1; i < word.length(); i++)
                if (cap(word[i])) count++;

            if (count == 1 || count == word.length())
                return true;
            
            return false;
        } else {
            for (int i = 1; i < word.length(); i++)
                if (cap(word[i]))
                    return false;
        }
        return true;
    }
};