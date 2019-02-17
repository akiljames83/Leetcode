class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!haystack.size()) {
            if (!needle.size())
                return 0;
            else
                return -1;
        }
        if (!needle.size()) return 0;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0] and i + needle.size() <= haystack.size()){
                int posH = i+1;
                int posN = 1;
                while (posH < haystack.length() and posN < needle.size()) {
                    if (haystack[posH++] != needle[posN++])
                        break;
                }
                        
                if (posN == needle.length() && haystack[posH-1] == needle[posN-1])
                    return i;
            }
        }
        return -1;
    }
};