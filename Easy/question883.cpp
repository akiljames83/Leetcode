class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        if (!grid.size()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> max_rows(rows, 0);
        vector<int> max_cols(cols, 0);
        int exists{};
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                int cur = grid[i][j];
                if (cur) exists++;
                if (cur > max_cols[j]) max_cols[j] = cur;
                if (cur > max_rows[i]) max_rows[i] = cur;
            }
        }
        for (auto r: max_rows){
            //cout << "R -> " << r << endl;
            exists += r;
        }
        for (auto c: max_cols) {
            //cout << "C -> " << c << endl;
            exists += c;
        }
        return exists;
    }
};