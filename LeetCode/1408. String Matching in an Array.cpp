class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> ret;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i] == words[j]) {
                    continue;
                }
                if (words[i].find(words[j]) != string::npos) {
                    ret.insert(words[j]);
                }
                if (words[j].find(words[i]) != string::npos) {
                    ret.insert(words[i]);
                }
            }
        }
        return {ret.begin(), ret.end()};
    }
};
