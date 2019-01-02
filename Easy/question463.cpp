class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        stack< pair<int, int> > points;
        set< pair<int, int> > island;
        vector<pair <int, int>> checks{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
        int rows = grid.size();
        int cols = grid[0].size();
        int border{0};
        // Find first point in grid
        for (int i = 0; i < rows; i ++){
            bool done = false;
            for (int j = 0; j < cols; j++){
                if (grid[i][j]) {
                    done = true;
                    points.push(make_pair(i,j));
                    island.insert(make_pair(i,j));
                    break;
                }
                
            }
            if (done) 
                break;
        }
        while (!points.empty()) {
            pair<int, int> cur = points.top();
            points.pop();
            for (pair <int, int> p : checks) {
                int first = cur.first + p.first;
                int second = cur.second + p.second;
                if ((first > -1) and (first < rows)){
                    if ((second > -1) and (second < cols) and grid[first][second]) {
                        pair <int, int> newpair = make_pair(first, second);
                        if (island.find(newpair) == island.end()) {
                            points.push(newpair);
                            island.insert(newpair);
                            //border -= 2;
                        }
                    }
                }  
            }
        }
           
        for (auto p : island)
            for (auto c : checks)
                if (island.find(make_pair(p.first + c.first, p.second + c.second)) != island.end())
                    border--;
        
        return border + island.size()*4;
    }
};