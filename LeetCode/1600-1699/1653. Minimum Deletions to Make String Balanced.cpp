class Solution {
public:
    int minimumDeletions(string s) {
        int dp = 0;
        int count_b = 0;
        for (char c : s) {
            if (c == 'b') {
                count_b++;
            } else { // == 'a'
                // either remove 'a', or all previous 'b's.
                dp = min(dp + 1, count_b);
            }
        }
        return dp;
    }
};
