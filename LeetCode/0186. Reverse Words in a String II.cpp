class Solution {
public:
    void reverseWords(vector<char>& s) {
        for (int lo = 0, hi = 0; hi < s.size(); lo = ++hi) {
            while (hi < s.size() and s[hi] != ' ') {
                hi++;
            }
            
            reverse(s.begin() + lo, s.begin() + hi);
        }
        
        reverse(s.begin(), s.end());
    }
};
