// Split
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

// Join
string join(const vector<string>& words, const string& s) {
    if (words.empty()) {
        return "";
    }
    string res = words.at(0);
    for (int i = 1; i < words.size(); i++) {
        res += s + words.at(i);
    }
    return res;
}
