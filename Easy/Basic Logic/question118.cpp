class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (!numRows)
            return res;
        res.push_back(vector<int>(1,1));
        if (numRows == 1)
            return res;
        int row_len = 2;
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp(row_len);
            tmp[0] = 1;
            tmp[row_len-1] = 1;
            if (row_len++ == 2) {
                res.push_back(tmp);
                continue;
            }
            auto prev = res.back();
            for (int i = 1; i < prev.size(); i++){
                tmp[i] = prev[i] + prev[i-1];
            }
            res.push_back(tmp);
        }
        return res;
    }
};