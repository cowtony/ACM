class Solution {
public:
    /*
     * @param timestamp: the current timestamp
     * @param event: the string to distinct different event
     * @param rate: the format is [integer]/[s/m/h/d]
     * @param increment: whether we should increase the counter
     * @return: true or false to indicate the event is limited or not
     */
    bool isRatelimited(int timestamp, string event, string rate, bool increment) {
        limits[event] = parseRate(rate);
        
        int first_valid_idx = upper_bound(events[event], timestamp - limits[event].second);
        bool limited = events[event].size() - first_valid_idx >= limits[event].first;
        
        if (increment and !limited) {
            events[event].push_back(timestamp);
        }

        return limited;
    }
    
private:
    unordered_map<string, pair<int, int>> limits; // <event, <count, in time(sec)>>
    unordered_map<string, vector<int>> events;  // <event, {event times}>
    
    pair<int, int> parseRate(string rate) {
        int num = stoi(rate.substr(0, rate.find('/')));
        string unit = rate.substr(rate.find('/') + 1);
        
        if (unit == "s") {
            return {num, 1};
        } else if (unit == "m") {
            return {num, 60};
        } else if (unit == "h") {
            return {num, 60 * 60};
        } else if (unit == "d") {
            return {num, 60 * 60 * 24};
        }
    }
    
    int upper_bound(const vector<int>& sorted_num, int target) {
        int lo = 0, hi = sorted_num.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (sorted_num[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
