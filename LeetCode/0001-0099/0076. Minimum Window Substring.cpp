class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> COUNT;
        for (char c : t) {
            COUNT[c]++;    
        }
        
        int lo = 0, hi = -1;
        int correct = 0;
        unordered_map<char, int> count;
        int min_length = INT_MAX;
        string ret;
        while (true) {
            if (correct < COUNT.size()) {
                hi++;
                if (hi >= s.length()) {
                    break;
                }
                if (COUNT.find(s[hi]) != COUNT.end()) {
                    count[s.at(hi)]++;
                    if (count[s.at(hi)] == COUNT[s.at(hi)]) {
                        correct++;
                    }
                }
            } else {
                if (COUNT.find(s[lo]) != COUNT.end()) {
                    if (count[s.at(lo)] == COUNT[s.at(lo)]) {
                        correct--;
                    }
                    count[s.at(lo)]--;
                }
                lo++;
            }
            if (correct >= COUNT.size()) {
                if (min_length > hi - lo + 1) {
                    ret = s.substr(lo, hi - lo + 1);
                    min_length = ret.length();
                }
            }
        }
        return ret;
    }
};
