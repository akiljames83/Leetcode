class Solution {
public:
    int compress(vector<char>& chars) {
        if ((chars.size() < 2))
            return chars.size();
        char cur = chars.front();
        int count = 1;
        int prev = 1;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == cur)
                count++;
            else {
                auto front = chars.begin() + prev;
                if (count > 1)
                    while(count){
                        chars[prev++] = '0' + count % 10;
                        count /= 10;
                    }
                reverse(front, chars.begin() + prev);
                cur = chars[i];
                chars[prev++] = chars[i];
                count = 1;
            }
        }  
        auto front = chars.begin() + prev;
        if (count > 1)
            while(count){
                chars[prev++] = '0' + count % 10;
                count /= 10;
            }
        reverse(front, chars.begin() + prev);
        return prev;
    }
};