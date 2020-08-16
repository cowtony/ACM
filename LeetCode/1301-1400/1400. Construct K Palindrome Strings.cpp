class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) {
            return false;
        }
        
        vector<int> m(26, 0);
        for (char c : s) {
            m[c - 'a']++;
        }
        
        int count = 0;
        for (int num : m) {
            if (num % 2 == 1) {
                count++;
            }
        }
        
        return count <= k;
    }
};
