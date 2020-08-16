class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        map<int, int> event;
        for (auto interval : intervals) {
            event[interval[0]]++;
            event[interval[1]]--;
        }
        
        int count = 0;
        for (auto p : event) {
            count += p.second;
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
};
