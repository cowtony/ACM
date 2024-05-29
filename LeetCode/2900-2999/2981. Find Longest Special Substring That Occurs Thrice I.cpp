class Solution {
public:
    int maximumLength(string s) {
        vector<map<int, int>> count_pq(26);

        int result = -1;
        for (int i = 0, count = 0; i < s.length(); i++) {
            count++;
            if (i == s.length() - 1 || s[i] != s[i + 1]) {
                for (int j = 1; j <= 3 && count > j - 1; j++) {
                    count_pq[s[i] - 'a'][count - (j - 1)] += j;
                    if (count_pq[s[i] - 'a'][count - (j - 1)] >= 3) {
                        result = max(result, count - (j - 1));
                    }
                }
                count = 0;
            }
        }
        return result;
    }
};
