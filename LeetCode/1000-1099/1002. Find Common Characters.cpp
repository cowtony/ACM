class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> total_count(26, INT_MAX);
        for (const string& word : words) {
            vector<int> count(26, 0);
            for (char c : word) {
                count[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                total_count[i] = min(total_count[i], count[i]);
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (total_count[i]--) {
                result.push_back(string(1, 'a' + i));
            }
        }
        return result;
    }
};
