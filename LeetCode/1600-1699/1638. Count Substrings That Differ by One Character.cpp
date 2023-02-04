class Solution {
public:
    int countSubstrings(string s, string t) {
        return helper(s, t) + helper(t, s, 1);  // shift = 1 to skip recount 0 & 0 starting point.
    }

    int helper(const string& s, const string& t, int shift = 0) {
        int result = 0;
        for (; shift < t.length(); shift++) {
            int privious_same = 0, counter = 0;
            for (int i = 0, j = shift; i < s.length() && j < t.length(); ++i, ++j) {
                counter++;
                if (s[i] != t[j]) {
                    privious_same = counter;
                    counter = 0;
                }
                result += privious_same;
            }
        }
        return result;
    }
};