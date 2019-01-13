class Solution {
public:
    float distance(vector<int>&p){
        return p[0]*p[0] + p[1]*p[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        struct Point {
            vector<int> p;
            float d;
            Point(vector<int> v, float dist) : d(dist), p(v) {}
        };
        vector<Point> point_arr;
        for (auto pair : points){
            int d = distance(pair);
            cout << d << endl;
            point_arr.emplace_back(Point(pair, d));
        }
        std::sort(point_arr.begin(), point_arr.end(), [](const Point& p1, const Point & p2){
            return p1.d < p2.d;
        });
        vector<vector<int>> res;
        for (int i = 0; i < point_arr.size(); i++){
            if (res.size() == K)
                break;
            res.emplace_back(point_arr[i].p);
        }
        return res;
            
            
    }
};