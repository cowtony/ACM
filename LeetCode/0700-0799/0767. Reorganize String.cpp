class Solution {
public:
    string reorganizeString(string S) {
        vector<int> count(26, 0);
        for (char c : S) {
            count[c - 'a']++;
        }
        
        int max_occurance = 0;
        int max_idx;
        for (int i = 0; i < 26; i++) {
            if (count[i] > max_occurance) {
                max_occurance = count[i];
                max_idx = i;
            }
        }
        
        if (max_occurance > S.length() / 2 + S.length() % 2) {
            return "";
        }
        
        string res(S.length(), ' ');
        int idx = 0; // Start filling even cell.
        for (int i = 0, j = max_idx; i < 26; i++, j = (j + 1) % 26) {
            for (int k = 0; k < count[j]; k++) {
                res[idx] = j + 'a';
                idx += 2;
                if (idx >= res.length()) {
                    idx = 1; // Now starting to fill odd cells.
                }
            }
        }
        
        return res;
    }
};
