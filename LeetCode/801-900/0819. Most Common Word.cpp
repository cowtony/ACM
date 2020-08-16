class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (char& c : paragraph) {
            if (c >= 'A' and c <= 'Z') {
                c = c - 'A' + 'a';
            } else if (c < 'a' or c > 'z') {
                c = ' ';
            }
        }
        unordered_set<string> dict(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (string word : split(paragraph)) {
            if (word.empty()) {
                continue;
            }
            if (dict.find(word) == dict.end()) {
                count[word]++;
            }
        }
        
        int max_count = 0;
        string res;
        for (auto p : count) {
            if (max_count < p.second) {
                max_count = p.second;
                res = p.first;
            }
        }
        return res;
    }
    
    vector<string> split(string s) {
        vector<string> res;
        size_t pos = 0;
        while (pos < s.length()) {
            size_t del = s.find(' ', pos);
            if (del == string::npos) {
                del = s.length();
            }
            res.push_back(s.substr(pos, del - pos));
            pos = del + 1;
        }
        return res;
    }
};
