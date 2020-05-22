class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        
        multimap<int, char> invert;
        for (auto p : count) {
            invert.insert(make_pair(p.second, p.first));
        }
        
        string res;
        for (auto it = invert.rbegin(); it != invert.rend(); it++) {
            res += string(it->first, it->second);
        }
        return res;
    }
};
