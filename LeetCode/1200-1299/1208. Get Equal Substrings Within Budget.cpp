class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int result = 0;
        int cost = 0;
        for (int l = 0, r = 0; r < s.length(); r++) {
            cost += abs(s[r] - t[r]);
            while (cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                l++;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
