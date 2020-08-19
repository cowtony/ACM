class Solution {
public:
    string toGoatLatin(string S) {
        const unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u'});
        vector<string> words = split(S);
        string a;
        for (string& word : words) {
            if (vowel.find(tolower(word[0])) == vowel.end()) {
                word = word.substr(1) + word[0];
            }
            a += "a";
            word += "ma" + a;
        }
        
        return join(words);
    }
    
    vector<string> split(string s, string delimiter = " ") {
        vector<string> res;
        size_t p = 0;
        while (p <= s.length()) {
            size_t pos = s.find(delimiter, p);
            if (pos == string::npos) {
                pos = s.length();
            }
            res.emplace_back(s.substr(p, pos - p));
            p = pos + delimiter.length();
        }
        return res;
    }
    
    string join(const vector<string>& words, const string& delimiter = " ") {
        if (words.empty()) {
            return "";
        }
        string res = words.at(0);
        for (int i = 1; i < words.size(); i++) {
            res += delimiter + words.at(i);
        }
        return res;
    }
};
