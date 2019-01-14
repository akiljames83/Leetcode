class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int ssize = s.size();
        int gsize = g.size();
        int i{}, j{};
        while( i != ssize and j != gsize){
            if (s[i++] >= g[j]){
                j++;
            }
        }
        return j;
    }
};