class Solution {
public:
    /**
     * @param s1: a string
     * @param s2: a string
     * @return: if s2 contains the permutation of s1
     */
    bool checkInclusion(string &s1, string &s2) {
        vector<int> p_count(26, 0);
        for (char c : s1) {
            p_count[c - 'a']++;
        }
        
        int remain = s1.length();
        vector<int> s_count(26, 0);
        for (int i = 0; i < s2.length(); i++) {
            s_count[s2[i] - 'a']++;
            if (s_count[s2[i] - 'a'] <= p_count[s2[i] - 'a']) {
                remain--;
            }
            
            if (i >= s1.length()) {
                if (s_count[s2[i - s1.length()] - 'a'] <= p_count[s2[i - s1.length()] - 'a']) {
                    remain++;
                }
                s_count[s2[i - s1.length()] - 'a']--;

            }
            
            if (remain == 0) {
                return true;
            }
        }
        return false;
    }
};
