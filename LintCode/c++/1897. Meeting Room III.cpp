class Solution {
public:
    /**
     * @param intervals: the intervals
     * @param rooms: the sum of rooms
     * @param ask: the ask
     * @return: true or false of each meeting
     */
    vector<bool> meetingRoomIII(vector<vector<int>> &intervals, int rooms, vector<vector<int>> &ask) {
        map<int, int> events;
        for (auto interval : intervals) {
            events[interval[0]]++;
            events[interval[1]]--;
        }
        
        map<int, int> full_intervals;
        int room_count = 0, first_time = -1;
        for (auto p : events) {
            if (p.second == 0) {
                continue;
            }
            room_count += p.second;
            
            if (room_count >= rooms and first_time < 0) {
                first_time = p.first;
            } 
            if (room_count < rooms and first_time >= 0) {
                full_intervals[first_time] = p.first;
                first_time = -1;
            }
        }
        
        vector<bool> ret;
        for (auto a : ask) {
            ret.push_back(help(full_intervals, a));
        }
        return ret;
    }
    
    bool help(map<int, int>& full_intervals, vector<int> interval) {
        auto it = full_intervals.lower_bound(interval[0]);
        if (it != full_intervals.end()) {
            if (it->first < interval[1]) {
                return false;
            }
        }
        if (it != full_intervals.begin()) {
            it--;
            if (it->second > interval[0]) {
                return false;
            }
        }
        return true;
    }
};
