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

// Better solution using a queue:
class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() = default;
    
    int ping(int t) {
        q.push(t);
        while((q.front() + 3000 < t))
            q.pop();
        return static_cast<int>(q.size());
    }
};