class Solution {
public:
    int numSplits(string s) {
        vector<int> left_count(26, 0), right_count(26, 0);
        int left_distinct = 0, right_distinct = 0;
        
        for (char c : s) {
            if (right_count[c - 'a']++ == 0) {
                right_distinct++;
            }
        }
        
        int res = 0;
        for (char c : s) {
            if (left_count[c - 'a']++ == 0) {
                left_distinct++;
            }
            if (--right_count[c - 'a'] == 0) {
                right_distinct--;
            }
            
            if (left_distinct == right_distinct) {
                res++;
            }
        }
        return res;
    }
};
