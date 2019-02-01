class Solution {
public:
    int minAddToMakeValid(string S) {
        int opens = 0;
        int count = 0;
        for (auto c: S) {
            if (c == '(')
                opens++;
            else {
                if (opens)
                    opens--;
                else
                    count++;
            }
        }
        return count + opens;
    }
};