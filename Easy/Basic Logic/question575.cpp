// Lazy solution
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> cset;
        for (auto c : candies)
            cset.insert(c);
        return candies.size()/2 >= cset.size() ? cset.size() : candies.size()/2;
    }
};

// Better solution:
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> cset(candies.begin(), candies.end());
        return candies.size()/2 >= cset.size() ? cset.size() : candies.size()/2;
    }
};
