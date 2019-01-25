class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i','o','u', 'A', 'E', 'I', 'O', 'U'};
    string reverseVowels(string s) {
        if (!s.length() || s.length() == 1)
            return s;
        int front{0};
        int back{s.length()-1};
        bool fvowel{vowels.find(s[front]) != vowels.end()};
        bool bvowel{vowels.find(s[back]) != vowels.end()};
        while(front < back){
            if (fvowel and bvowel){
                swap(s[front++], s[back--]);
                fvowel = vowels.find(s[front]) != vowels.end();
                bvowel = vowels.find(s[back]) != vowels.end();
            } else if (fvowel) {
                bvowel = vowels.find(s[--back]) != vowels.end();
            } else if (bvowel) {
                fvowel = vowels.find(s[++front]) != vowels.end();
            } else {
                fvowel = vowels.find(s[++front]) != vowels.end();
                bvowel = vowels.find(s[--back]) != vowels.end();
            }
        }
        return s;
    }
};