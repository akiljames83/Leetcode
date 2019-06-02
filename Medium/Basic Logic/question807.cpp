class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int count{};
        vector<vector<int>> n_grid = grid;
        vector<int> max_row(grid[0].size(), 0);
        
        for (int i = 0; i < grid.size(); i++) {
            int max = *max_element(grid[i].begin(), grid[i].end());
            
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] > max_row[j])
                    max_row[j] = grid[i][j];
                n_grid[i][j] = max; 
            }
        }
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                count += (min(max_row[j], n_grid[i][j]) - grid[i][j]);
            }
        }        
        
        return count;
    }
};

// Better Version
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int count{};
        vector<int> max_col(grid.size(), 0);
        vector<int> max_row(grid[0].size(), 0);
        
        for (int i = 0; i < grid.size(); i++) {
            max_col[i] = *max_element(grid[i].begin(), grid[i].end());
            
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] > max_row[j]) max_row[j] = grid[i][j];

        }
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                count += (min(max_row[j], max_col[i]) - grid[i][j]);
            }
        }        
        
        return count;
    }
};