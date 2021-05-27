class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int lo = 1, hi = 1E9;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (possible(position, m, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
    
    bool possible(vector<int>& position, int m, int gap) {
        int last = position[0];
        m--;
        for (int i = 1; i < position.size() and m > 0; i++) {
            if (position[i] - last >= gap) {
                m--;
                last = position[i];
            }
        }
        return m == 0;
    }
};
