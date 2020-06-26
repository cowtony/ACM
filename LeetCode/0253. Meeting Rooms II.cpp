class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> events; // Key = time, Value = count;
        for (const vector<int>& interval : intervals) {
            events[interval[0]]++;
            events[interval[1]]--;
        }
        
        int rooms = 0;
        int max_rooms = 0;
        for (auto event : events) {
            rooms += event.second;
            max_rooms = max(max_rooms, rooms);
        }
        
        return max_rooms;
    }
};
