class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        // Preprocess
        unordered_map<int, vector<int>> seen;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                if (seen.find(0) == seen.end()) {
                    seen[0] = {i, i};
                }
                continue;
            }
            int val = 0;
            for (int j = i; j < i + 30 && j < s.length(); j++) {
                val = (val << 1) + (s[j] - '0');
                if (seen.find(val) == seen.end()) {
                    seen[val] = {i, j};
                }
            }
        }
        
        vector<vector<int>> result;
        for (const auto& query : queries) {
            int decimal = query[0] ^ query[1];
            if (seen.find(decimal) == seen.end()) {
                result.push_back({-1, -1});
            } else {
                result.push_back(seen.at(decimal));
            }
        }
        return result;
    }
};
