class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int num{};
        int size = s.size();
        for (int i = 0; i < size; i++){
            if (s[i] == 'I'){
                if (i + 1 != size ){
                    if (s[i+1] == 'V')
                        num += 4;
                    else if (s[i+1] == 'X')
                        num += 9;
                    else
                    {
                        num += map[s[i]];
                        continue;
                    }
                    i++;
                    continue;
                }
            } else if (s[i] == 'X') {
                if (i + 1 != size ){
                    if (s[i+1] == 'L')
                        num += 40;
                    else if (s[i+1] == 'C')
                        num += 90;
                    else
                    {
                        num += map[s[i]];
                        continue;
                    }
                    i++;
                    continue;
                }
                
            } else if (s[i] == 'C') {
                if (i + 1 != size ){
                    if (s[i+1] == 'D')
                        num += 400;
                    else if (s[i+1] == 'M')
                        num += 900;
                    else
                    {
                        num += map[s[i]];
                        continue;
                    }
                    i++;
                    continue;
                }
            }
            num += map[s[i]];
        }
        return num;
    }
};