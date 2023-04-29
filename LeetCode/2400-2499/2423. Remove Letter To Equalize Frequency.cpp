class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> count(26, 0);
        for (char c : word) {
            count[c - 'a']++;
        }
        sort(count.begin(), count.end());
        map<int, int> count2;
        for (int c : count) {
            if (c > 0) {
                count2[c]++;
            }
        }
        cout << count2.size();
        if (count2.size() == 1 && (count2.begin()->first == 1 || count2.begin()->second == 1)) {
            // abcd or aaaa
            return true;
        }
        if (count2.size() != 2) {
            return false;
        }
        if (count2.begin()->first == 1 && count2.begin()->second == 1) {
            // abbbccc
            return true;
        }
        if (count2.rbegin()->second == 1 && count2.rbegin()->first - count2.begin()->first == 1) {
            // aaabbbcccc
            return true;
        }
        return false;
    }
};
