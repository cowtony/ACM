class Solution {
public:
    int hIndex(vector<int>& citations) {
        int lo = 0, hi = citations.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (citations[mid] >= citations.size() - mid) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return citations.size() - lo;
    }
};
