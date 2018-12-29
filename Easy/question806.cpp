class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int tsum{}, lines{1}, w;
        for (auto s: S){
            w = widths[s - 97];
            if (tsum + w <= 100) 
                tsum += w;
            else {
                lines++;
                tsum = w;
            }
        }
        return {lines, tsum};
    }
};