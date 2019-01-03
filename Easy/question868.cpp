class Solution {
public:
    int binaryGap(int N) {
        vector<int> loc;
        int tmp = N;
        int cnt{0};
        while(tmp){
            if (tmp & 0x01) 
                loc.push_back(cnt);
            cnt++;
            tmp >>= 1;
        }
        int dist{0};
        for (int i = 1; i < loc.size(); i++){
            int cur = loc[i] - loc[i - 1];
            if (cur > dist) 
                dist = cur;
        }
        return dist;
    }
};