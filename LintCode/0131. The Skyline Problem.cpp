// LeetCode 218: https://leetcode.com/problems/the-skyline-problem/
class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
        map<int, multiset<int>> events;
        for (const vector<int>& building : buildings) {
            events[building[0]].insert(building[2]);
            events[building[1]].insert(-building[2]);
        }
        
        multiset<int, greater<int>> heights;
        vector<vector<int>> ans;
        int previous_height = 0;
        int previous_x = -1;
        for (auto p : events) {
            for (int h : p.second) {
                if (h > 0) {
                    heights.emplace(h);
                } else {
                    heights.erase(heights.find(-h));
                }
            }
            
            int current_height;
            if (heights.empty()) {
                current_height = 0;
            } else {
                current_height = *heights.begin();
            }
            
            
            if (current_height != previous_height) {
                if (previous_x >= 0 and previous_height > 0) {
                    ans.push_back({previous_x, p.first, previous_height});
                }
                previous_x = p.first;
            }
            
            previous_height = current_height;
        }
        return ans;
    }
};
