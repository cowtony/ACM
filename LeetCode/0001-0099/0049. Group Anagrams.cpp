class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (const string& s : strs) {
            string ss = sort(s);
            um[ss].push_back(s);
        }
        vector<vector<string>> ret;
        for (const auto& pair : um) {
            ret.push_back(pair.second);
        }
        return ret;
    }
    
    // This sort is O(2n).
    string sort(const string& s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string ret;
        for (int i = 0; i < count.size(); i++) {
            ret += string(count[i], i + 'a');
        }
        return ret;
    }
};
