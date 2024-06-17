class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int result = -1;
        for (int i = 0; i < strs.size(); i++) {
            bool is_sub = false;
            for (int j = 0; j < strs.size(); j++) {
                if (j == i) {
                    continue;
                }
                if (isSubsequence(strs[i], strs[j])) {
                    is_sub = true;
                    break;
                }
            }
            if (!is_sub) {
                result = max(result, int(strs[i].length()));
            }
        }
        return result;
    }

    bool isSubsequence(const string& sub, const string& raw) {
        for (int i = 0, j = 0; i < sub.length(); i++, j++) {
            while (j < raw.length() && sub[i] != raw[j]) {
                j++;
            }
            if (j == raw.length()) {
                return false;
            }
        }
        return true;
    }
};
