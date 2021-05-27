class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = 0, hi = 1E9 + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (helper(bloomDay, m, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo == 1E9 + 1? -1:lo;
    }
    
    bool helper(const vector<int>& bloomDay, int m, int k, int limit) {
        int len = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay.at(i) > limit) {
                m -= len / k;
                len = 0;
            } else {
                len++;
            }
        }
        m -= len / k;
        
        return m <= 0;
    }
};
