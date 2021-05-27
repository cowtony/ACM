class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        
        int len = words.front().length();
        
        unordered_map<string, int> m; // word, count
        for (string word : words) {
            m[word]++;
        }
        
        vector<int> ret;
        for (int i = 0; i + len * words.size() <= s.length(); i++) {
            unordered_map<string, int> seen;
            for (int j = i, c = 0; c < words.size(); j += len, c++) {
                string word = s.substr(j, len);
                if (m.find(word) == m.end()) {
                    goto end;
                }
                seen[word]++;
                if (seen[word] > m[word]) {
                    goto end;
                }
            }
            ret.emplace_back(i);
            end:;
        }
        
        return ret;
    }
};
