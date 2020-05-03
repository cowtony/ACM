class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> count_sort1(26), count_sort2(26);
        for (char c : s1) {
            count_sort1[c - 'a']++;
        }
        for (char c : s2) {
            count_sort2[c - 'a']++;
        }
        return checkIfS1BreakS2(count_sort1, count_sort2) or checkIfS1BreakS2(count_sort2, count_sort1);
    }
    
    bool checkIfS1BreakS2(vector<int> count_sort1, vector<int> count_sort2) {
        int i = 0, j = 0;
        while (i < 26 and j < 26) {
            while (i < 26 and count_sort1[i] == 0) {
                i++;
            }
            while (j < 26 and count_sort2[j] == 0) {
                j++;
            }
            if (i < j) {
                return false;
            }
            if (i >= 26 or j >= 26) {
                break;
            }
            int min_cnt = min(count_sort1[i], count_sort2[j]);
            count_sort1[i] -= min_cnt;
            count_sort2[j] -= min_cnt;
        }
        return true;
    }
};
