class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        result.reserve(queries.size());
        for (const string& query : queries) {
            result.push_back(match(query, pattern));
        }
        return result;
    }

    bool match(const string& query, const string& pattern) {
        int i = 0;
        for (char c : query) {
            if (i < pattern.size() && c == pattern[i]) {
                i++;
            } else if (c >= 'A' && c <= 'Z') {
                return false;
            }
        }
        return i == pattern.length();
    }
};
