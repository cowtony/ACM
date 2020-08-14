class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(256, 0);
        for (char c : s) {
            count[c]++;
        }
        
        bool hasOdd = false;
        int res = 0;
        for (int c : count) {
            res += c - c % 2;
            if (c % 2 == 1) {
                hasOdd = true;
            }
        }
        return res + (hasOdd? 1 : 0);
    }
};
