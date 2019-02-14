class Solution {
public:
    void checkSides(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        if (i -1 > -1 and grid[i-1][j] == '1') checkSides(i-1, j, grid);
        if (j + 1 < grid[0].size() and grid[i][j+1] == '1') checkSides(i, j+1, grid);
        if (i + 1 < grid.size() and grid[i+1][j] == '1') checkSides(i + 1, j, grid);
        if (j - 1 > -1 and grid[i][j-1] == '1') checkSides(i, j - 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count{};
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1')
                    checkSides(i + 0*(count++), j, grid);
            }
        }
        return count;
    }
};