class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        vector<bool> allow(256, false);
        for (char c : allowed) {
            allow[c] = true;
        }
        for (const string& word : words) {
            if (consistent(allow, word)) {
                count++;
            }
        }
        return count;
    }

    bool consistent(const vector<bool>& allow, const string& word) {
        for (char c : word) {
            if (allow[c] == false) {
                return false;
            }
        }
        return true;
    }
};
