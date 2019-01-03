// Lazy solution
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> cset;
        for (auto c : candies)
            cset.insert(c);
        return candies.size()/2 >= cset.size() ? cset.size() : candies.size()/2;
    }
};

// Better solution:

