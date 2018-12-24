class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> amap;
        int max_count = A.size()/2;
        vector<int>::iterator it = A.begin();
        //std::count(A.begin(), A.end(), )
        for(it; it != A.end(); it++){
            if(amap.find(*it) != amap.end()){
                amap[*it] += 1;
            } else {
                if(std::count(A.begin(), A.end(), *it) == max_count)
                    return *it;
                amap[*it] = 1;
            }
        }
    }
};