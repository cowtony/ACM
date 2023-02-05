class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        // Init `left`, `right` vectors.
        queue<int> q;
        vector<pair<int, int>> left;   // The <end_position, prizes> for the left segment.
        vector<pair<int, int>> right;  // The <start_position, prizes> for the right segment.
        for (int pos : prizePositions) {
            while (!q.empty() && pos - q.front() > k) {
                if (right.empty() || right.back().first != q.front()) {
                    right.push_back({q.front(), q.size()});
                }
                q.pop();
            }
            q.push(pos);
            if (!left.empty() && left.back().first == pos) {
                left.rbegin()->second = q.size();
            } else {
                left.push_back({pos, q.size()});
            }
        }
        right.push_back({q.front(), q.size()});
        
        // Get the max prize for right segment start from i.
        vector<int> max_prize(right.size(), 0);
        *max_prize.rbegin() = right.back().second;
        for (int i = max_prize.size() - 2; i >= 0; i--) {
            max_prize[i] = max(right[i].second, max_prize[i + 1]);
        }

        // Scan through to find the maximum sum.
        int result = 0;
        int max_left = 0;
        int ptr = 0;
        for (int i = 0; i < left.size(); i++) {
            while (ptr < right.size() && right[ptr].first <= left[i].first) {
                ptr++;
            }
            max_left = max(max_left, left[i].second);
            int max_right = i + 1 < max_prize.size()? max_prize[i + 1] : 0;
            result = max(result, max_left + max_right);
        }
        
        return result;
    }
};
