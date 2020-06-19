class Solution {
public:
    string longestDupSubstring(string S) {
        int lo = 0, hi = S.length();
        string res;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            int idx = helper(S, mid);
            if (idx >= 0) {
                res = S.substr(idx, mid);
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }
    
    // Rolling hash.
    int helper(const string& s, int length) {
        uint32_t hash = 0;
        const uint32_t kBase = 26;
        uint32_t kBaseL = 1;
        for (int i = 0; i < length; i++) {
            hash = (hash * kBase + s[i] - 'a');
            kBaseL = (kBaseL * kBase);
        }
        
        unordered_set<uint32_t> um;
        um.insert(hash);
        for (int i = 1; i + length <= s.length(); i++) {
            hash = hash * kBase - (s[i - 1] - 'a') * kBaseL + s[i + length - 1] - 'a';
            if (um.find(hash) != um.end()) {
                return i;
            }
            um.insert(hash);
        }
        return -1;
    }
};
