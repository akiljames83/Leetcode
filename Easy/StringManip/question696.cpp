class Solution {
public:
    int countBinarySubstrings(string s) {
        int count{}, preCount{}, curCount{}, beginp{}, endp{};
        bool flip = false;
        char prev = s[0];
        
        while(endp != s.length()){
            
            if (s[++endp] == prev){
                if ((preCount >= curCount++) and flip)
                    count++;
        
            } else {
                if (flip) { 
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