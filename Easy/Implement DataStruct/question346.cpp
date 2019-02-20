class MovingAverage {
private:
    int size{0};
    int sum{0};
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if (this->q.size() == this->size) {
            this->sum -= this->q.front();
            this->q.pop();
        }
        this->sum += val;
        this->q.push(val);
        return static_cast<double>(this->sum)/this->q.size();
        
    }
};
