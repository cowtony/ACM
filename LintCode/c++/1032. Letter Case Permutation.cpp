class Solution {
public:
    /**
     * @param S: a string
     * @return: return a list of strings
     */
    vector<string> letterCasePermutation(string &S) {
        vector<string> ret;
        ret.push_back(S);
        for (int i = 0; i < S.length(); i++) {
            if (S[i] >= '0' and S[i] <= '9') {
                continue;
            }
            vector<string> ret_copy = ret;
            for (string& s : ret_copy) {
                s[i] = flip(s[i]);
            }
            ret.insert(ret.end(), ret_copy.begin(), ret_copy.end());
        }
        return ret;
    }
    
    char flip(char c) {
        if (c >= 'a' and c <= 'z') {
            return c - 'a' + 'A';
        } else {
            return c - 'A' + 'a';
        }
    }
};
