class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> amap;
        vector<int>::iterator it = A.begin();
        int max_count = A.size()/2;

        for(it; it != A.end(); it++){
            if(amap.find(*it) != amap.end()){
                continue;
            } else {
                if(std::count(A.begin(), A.end(), *it) == max_count)
                    return *it;
                amap[*it] = 1;
            }
        }
    }
};