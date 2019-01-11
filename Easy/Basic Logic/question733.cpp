class Solution {
public:
    bool validPoint(int first, int second, pair<int, int> dims){
        if (first > -1 and second > -1 and first < dims.first and second < dims.second)
            return true;
        return false;
    }
    void addPoints(queue<pair<int, int>>& q, pair<int,int>pos, pair<int, int> dims, unordered_set<int> &set){
        //cout << "Trying: (" << pos.first + 1 << "," << pos.second << ")" << endl;
        if (validPoint(pos.first + 1, pos.second, dims)) {
            //cout << "GOOD.1" << endl;
            pair<int, int> tmp = make_pair(pos.first + 1, pos.second);
            int t_val = dims.second*tmp.first + tmp.second;
            
            if (set.find(t_val) == set.end()) {
                //cout << t_val << endl;
                //cout << "(" << pos.first + 1<< "," << pos.second<< ")" << endl;
                q.push(make_pair(pos.first + 1, pos.second));
                set.insert(t_val);
            }
                
        }
        
        //cout << "Trying: (" << pos.first << "," << pos.second + 1 << ")" << endl;
        if (validPoint(pos.first , pos.second + 1, dims)) {
            pair<int, int> tmp = make_pair(pos.first , pos.second + 1);
            int t_val = dims.second*tmp.first + tmp.second;
            //cout << "C2 " <<  t_val << endl;
            if (set.find(t_val) == set.end()) {
                //cout << t_val << endl;
                //cout << "(" << pos.first - 1<< "," << pos.second<< ")" << endl;
                //cout << "Very Good" << endl;
                q.push(make_pair(pos.first , pos.second + 1));
                set.insert(t_val);
            }
                
        }
        
        //cout << "Trying: (" << pos.first - 1 << "," << pos.second << ")" << endl;
        if (validPoint(pos.first - 1, pos.second, dims)) {
            //cout << "GOOD.3" << endl;
            pair<int, int> tmp = make_pair(pos.first - 1, pos.second);
            int t_val = dims.second*tmp.first + tmp.second;
            if (set.find(t_val) == set.end()) {
                //cout << t_val << endl;
                //cout << "(" << pos.first - 1<< "," << pos.second<< ")" << endl;
                q.push(make_pair(pos.first - 1, pos.second));
                set.insert(t_val);
            }
                
        }
        
        //cout << "Trying: (" << pos.first << "," << pos.second - 1 << ")" << endl;
        if (validPoint(pos.first , pos.second - 1, dims)) {
            //cout << "GOOD.4" << endl;
            pair<int, int> tmp = make_pair(pos.first , pos.second - 1);
            int t_val = dims.second*tmp.first + tmp.second;
            if (set.find(t_val) == set.end()) {
                //cout << t_val << endl;
                //cout << "(" << pos.first + 0<< "," << pos.second - 1<< ")" << endl;
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
        //cout << "DESIRED COLOR: " << curColor << endl;
        while (!points.empty()){
            auto tmp = points.front();
            //cout << "("<< tmp.first << ", " << tmp.second << ")";
            //cout << " Color -> " << image[tmp.first][tmp.second] << endl;
            if (image[tmp.first][tmp.second] == curColor){
                addPoints(points, tmp, dims, set);
                image[tmp.first][tmp.second] = newColor;
            }
            points.pop();
        }
        return image;
        
    }
};