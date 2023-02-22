class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> segment;
        for (int i = 0; i < ranges.size(); ++i) {
            segment.emplace_back(make_pair(max(0, i - ranges[i]), i + ranges[i]));
        }
        sort(segment.begin(), segment.end());

        int current = 0;
        int future = 0;
        int count = 0;
        for (int i = 0; i < segment.size(); i++) {
            if (segment[i].first > future) {
                return -1;
            } else if (segment[i].first > current) {
                current = future;
                count++;
            }
            future = max(future, segment[i].second);
            if (future >= n) {
                return count + 1;
            }
        }
        return future < n? -1 : count;
    }
};
