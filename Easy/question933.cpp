auto __=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class RecentCounter {
private:
    int times [10000] {0};
    int count{0};
    int front[2]{0}; // index, value
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(front[1] == 0) front[1] = t;
        
        times[count++] = t;
        
        if((t - 3000 > 0) and (t - 3000 < front[1]))
            return count - front[0];
        
        while(front[1] + 3000 < t)
            front[1] = times[++front[0]];
         
        return count - front[0];
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
/*
["RecentCounter","ping","ping","ping","ping","ping"]
[[],[2196],[3938],[4723],[4775],[5952]]

["RecentCounter","ping","ping","ping","ping"]
[[],[1],[100],[3001],[3002]]
*/