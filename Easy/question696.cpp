class Solution {
public:
    int countBinarySubstrings(string s) {
        int count{};
        int preCount = 0;
        int curCount = 0;
        int beginp = 0;
        int endp = 0;
        bool flip = false;
        char prev = s[0];
        while(endp != s.length()){
            if (s[++endp] == prev){
                curCount++;
                if (flip) {
                    if ((preCount + 1 >= curCount)){
                        count++;
                    }
                }
            } else {
                if (flip) { // now inc
                    if ((preCount >= curCount)){
                        count++;
                    }    
                    flip = !flip;
                    endp = beginp;
                    prev = s[endp];
                    preCount = curCount;
                    curCount = 0;
                } else {
                    preCount = curCount;
                    curCount = 0;
                    prev = s[endp];
                    beginp = endp;
                    flip = !flip;
                }
            }
        }
        return count;
    }
};