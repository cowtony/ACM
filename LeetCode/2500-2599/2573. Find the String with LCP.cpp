class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        char c = 'a';
        string result(lcp.size(), '*');
        for (int i = 0; i < lcp.size(); i++) {
            if (lcp[i][i] + i != lcp.size()) { return ""; }
            if (result[i] == '*') {
                if (c > 'z') { return ""; }
                result[i] = c++;
            }
            for (int j = i + 1; j < lcp[0].size(); j++) {
                if (lcp[i][j] != lcp[j][i]) { return ""; }
                if (lcp[i][j] + j > lcp.size()) { return ""; }
                if (lcp[i][j] > 0) {
                    if (j + 1 < lcp.size() && lcp[i][j] - 1 != lcp[i + 1][j + 1]) {
                        return "";
                    }
                    result[j] = result[i];
                }
            }
        }
        return result;
    }
};
