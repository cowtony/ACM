// LeetCode 3: https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        // write your code here
        unordered_map<char, int> m;
        int start = 0;
        int max_length = 0;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end()) {
                start = max(start, m[s[i]] + 1);
            }
            m[s[i]] = i;
            max_length = max(max_length, i - start + 1);
        }
        return max_length;
    }
};
