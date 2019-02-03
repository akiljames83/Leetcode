class Solution {
public:
    string countAndSay(int n) {
        string tmp = "1";
        int i = 1;
        while(i++ < n){
            string ntmp{""};
            int count{1};
            char ch{tmp[0]};
            for(int j = 1; j < tmp.size(); j++){
                if (tmp[j] == ch){
                    count++;
                } else {
                    ntmp += to_string(count) + to_string(ch-'0');
                    ch = tmp[j];
                    count = 1;
                }
            }
            ntmp += to_string(count) + to_string(ch-'0');
            tmp = ntmp;
        }
        return tmp;
    }
};