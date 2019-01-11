class Solution {
public:
    bool validPoint(int first, int second, pair<int, int> dims){
        if (first > -1 and second > -1 and first < dims.first and second < dims.second)
            return true;
        return false;
    }
    void addPoints(queue<pair<int, int>>& q, pair<int,int>pos, pair<int, int> dims, unordered_set<int> &set){
        if (validPoint(pos.first + 1, pos.second, dims)) {
            pair<int, int> tmp = make_pair(pos.first + 1, pos.second);
            int t_val = dims.second*tmp.first + tmp.second;
            
            if (set.find(t_val) == set.end()) {
                q.push(make_pair(pos.first + 1, pos.second));
                set.insert(t_val);
            }
                
        }
        
        if (validPoint(pos.first , pos.second + 1, dims)) {
            pair<int, int> tmp = make_pair(pos.first , pos.second + 1);
            int t_val = dims.second*tmp.first + tmp.second;
            if (set.find(t_val) == set.end()) {
                q.push(make_pair(pos.first , pos.second + 1));
                set.insert(t_val);
            }
                
        }
        
        if (validPoint(pos.first - 1, pos.second, dims)) {
            pair<int, int> tmp = make_pair(pos.first - 1, pos.second);
            int t_val = dims.second*tmp.first + tmp.second;
            if (set.find(t_val) == set.end()) {
                q.push(make_pair(pos.first - 1, pos.second));
                set.insert(t_val);
            }
                
        }
        
        if (validPoint(pos.first , pos.second - 1, dims)) {
            pair<int, int> tmp = make_pair(pos.first , pos.second - 1);
            int t_val = dims.second*tmp.first + tmp.second;
            if (set.find(t_val) == set.end()) {
                q.push(make_pair(pos.first , pos.second - 1));
                set.insert(t_val);
            }
                
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() == 0 or image[0].size() == 0) return image;
        int curColor{image[sr][sc]};
        image[sr][sc] = newColor;
        pair<int, int> dims = make_pair(image.size(), image[0].size());
        queue<pair<int,int>> points;
        unordered_set<int> set;
        set.insert(sr*dims.second + sc);
        addPoints(points, make_pair(sr, sc), dims, set);
        while (!points.empty()){
            auto tmp = points.front();
            if (image[tmp.first][tmp.second] == curColor){
                addPoints(points, tmp, dims, set);
                image[tmp.first][tmp.second] = newColor;
            }
            points.pop();
        }
        return image;
        
    }
};