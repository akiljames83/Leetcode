class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (!intervals.size()) 
            return 0;
        auto func = [](Interval a, Interval b){return (a.start < b.start);};
        sort(intervals.begin(), intervals.end(), func);
        
        priority_queue<int> min_heap;
        min_heap.push(-1 * intervals[0].end);
        int max_room{1}, cur_room{1};
        for (int i = 1; i < intervals.size(); i++) {
            cur_room++;
            while (min_heap.size() and intervals[i].start >= -1 *min_heap.top()) {
                cur_room--;
                min_heap.pop();
            }
            max_room = max(max_room, cur_room);
            min_heap.push(-1 * intervals[i].end);
        }
        return max_room;
    }
};