class Solution {
public:
    vector<int> findPermutation(string s) {
        s += 'I'; // Since 'I' is triggering the reverse, always add a 'I' incase s end with a 'D'.
        
        // Init result with 1 to n.
        vector<int> res;
        for (int i = 1; i <= s.length(); i++) {
            res.push_back(i);
        }
        
        int last_d = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                reverse(res.begin() + last_d, res.begin() + i + 1);
                last_d = i + 1;
            }
        }
        
        return res;
    }
};
