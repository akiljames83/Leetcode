class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0)
            return m*n;
        int min_w{m};
        int min_h{n};
        for (auto v : ops){
            if (v[0] < min_w)
                min_w = v[0];
            if (v[1] < min_h)
                min_h = v[1];
        }
        return min_h * min_w;
    }
};