class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> schedule;
        for (const auto& trip : trips) {
            schedule[trip[1]] += trip[0];
            schedule[trip[2]] -= trip[0];
        }
        
        int passenger = 0;
        for (auto p : schedule) {
            passenger = passenger + p.second;
            if (passenger > capacity) {
                return false;
            }
        }
        return true;
    }
};
