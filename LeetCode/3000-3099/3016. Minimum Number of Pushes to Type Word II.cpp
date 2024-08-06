class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for (char c : word) {
            count[c - 'a']++;
        }

        sort(count.rbegin(), count.rend());

        int result = 0;
        int unique = 0;
        for (int cnt : count) {
            if (cnt > 0) {
                result += ((++unique + 7) / 8) * cnt; // 2-9 has 8 buttons
            }
        }
        return result;
    }
};
