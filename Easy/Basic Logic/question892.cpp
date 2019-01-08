class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        // pos*4 + 2
        // check left and right, min of the 2 hights, and sub height
        int height = grid.size();
        int width = grid[0].size();
        int SA{0};
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                if (grid[i][j]) SA += grid[i][j]*4 + 2;
                else continue;
                if ((j + 1 != width)){
                    SA -= min(grid[i][j], grid[i][j+1])*2;
                }
                if ((i + 1 != height)){
                    SA -= min(grid[i][j], grid[i+1][j])*2;
                }
            }
        }
        return SA;
    }
};