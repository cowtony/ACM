class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int small = 0, large = INT_MAX;
        for (int page: pages) {
            small = max(small, page);
        }
        int ans = 0;
        while (small <= large) {
            int mid = small + (large - small) / 2;
            cout << mid << endl;
            int people = 1;
            int t = 0;
            for (int page : pages) {
                if (t + page <= mid) {
                    t += page;
                } else {
                    people++;
                    if (mid < page) {
                        
                        
                    }
                    t = page;
                }
            }
            if (people > k) {
                small = mid + 1;
            } else {
                ans = mid;
                large = mid - 1;
            }
        }
        return ans;
    }
};
