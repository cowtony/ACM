class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> count(26, 0);
        for (char c : licensePlate) {
            if (c >= 'a' && c <= 'z') {
                count[c - 'a']++;
            } else if (c >= 'A' && c <= 'Z') {
                count[c - 'A']++;
            }
        }

        string result(16, 'z');
        for (const string& word : words) {
            if (isCompleting(word, count) && word.length() < result.length()) {
                result = word;
            }
        }
        return result;
    }

    bool isCompleting(const string& word, vector<int> count) {
        for (char c : word) {
            count[c - 'a']--;
        }
        for (int i : count) {
            if (i > 0) {
                return false;
            }
        }
        return true;
    }
};