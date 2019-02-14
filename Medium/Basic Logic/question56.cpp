class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (!intervals.size())
            return {};
        auto cmp = [](Interval a, Interval b){return a.start < b.start;};
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval>res;
        auto last = intervals.front();
        for (int i = 1; i != intervals.size(); i++) {
            if (last.end >= intervals[i].start) {
                last.end = max(intervals[i].end, last.end);
            } else {
                res.push_back(last);
                last = intervals[i];
            }
        }
        res.push_back(last);
        return res;
    }
};