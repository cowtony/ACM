class Solution {
public:
    /**
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string &s, string &p) {
        vector<int> p_count(26, 0);
        for (char c : p) {
            p_count[c - 'a']++;
        }
        
        vector<int> res;
        int remain = p.length();
        vector<int> s_count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            s_count[s[i] - 'a']++;
            if (s_count[s[i] - 'a'] <= p_count[s[i] - 'a']) {
                remain--;
            }
            
            if (i >= p.length()) {
                if (s_count[s[i - p.length()] - 'a'] <= p_count[s[i - p.length()] - 'a']) {
                    remain++;
                }
                s_count[s[i - p.length()] - 'a']--;

            }
            
            if (remain == 0) {
                res.push_back(i - p.length() + 1);
            }
        }
        return res;
    }
};
