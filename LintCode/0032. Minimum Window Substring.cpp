// LeetCode 76: https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here
        if (target.empty()) {
            return "";
        }
        unordered_map<char, int> COUNT;
        for (char c : target) {
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
                if (hi >= source.length()) {
                    break;
                }
                if (COUNT.find(source[hi]) != COUNT.end()) {
                    count[source.at(hi)]++;
                    if (count[source.at(hi)] == COUNT[source.at(hi)]) {
                        correct++;
                    }
                }
            } else {
                if (COUNT.find(source[lo]) != COUNT.end()) {
                    if (count[source.at(lo)] == COUNT[source.at(lo)]) {
                        correct--;
                    }
                    count[source.at(lo)]--;
                }
                lo++;
            }
            if (correct >= COUNT.size()) {
                if (min_length > hi - lo + 1) {
                    ret = source.substr(lo, hi - lo + 1);
                    min_length = ret.length();
                }
            }
        }
        return ret;
    }
};
