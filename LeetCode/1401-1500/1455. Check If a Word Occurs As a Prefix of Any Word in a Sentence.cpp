class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto words = split(sentence, " ");
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(searchWord) == 0) {
                return i + 1;
            }
        }
        return -1;
    }
    
    vector<string> split(string s, string delimiter) {
        vector<string> res;
        size_t p = 0;
        while (true) {
            size_t pos = s.find(delimiter, p);
            if (pos != string::npos) {
                res.emplace_back(s.substr(p, pos - p));
                p = pos + delimiter.length();
            } else {
                res.emplace_back(s.substr(p));
                break;
            }
        }
        return res;
    }
};
