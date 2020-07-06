class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> count;
        for (int h : hand) {
            count[h]++;
        }
        
        deque<int> open_straight; // write down the start value & their count.
        
        int previous_val;
        for (auto it = count.begin(); it != count.end(); it++) {
            
            if (!open_straight.empty() and (it->first - previous_val != 1 or it->second < open_straight.size())) {
                return false;
            }
            previous_val = it->first;
            it->second -= open_straight.size();

            if (it->second < 0) {
                return false;
            }
            while (it->second--) {
                open_straight.push_back(it->first);
            }
            while (!open_straight.empty() and it->first - open_straight.front() + 1 == W) {
                open_straight.pop_front();
            }
        }
        
        return open_straight.empty();
    }
};
