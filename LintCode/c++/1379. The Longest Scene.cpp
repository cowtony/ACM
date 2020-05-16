class Solution {
public:
    /**
     * @param str: The scene string
     * @return: Return the length longest scene
     */
    int getLongestScene(string &str) {
        unordered_map<char, int> start;
        unordered_map<char, int> end;
        for (int i = 0; i < str.length(); i++) {
            if (start.find(str[i]) == start.end()) {
                start[str[i]] = i;
            } else {
                end[str[i]] = i;
            }
        }
        
        map<int, int> scan;
        for (auto p : end) {
            scan[start[p.first]]++;
            scan[p.second]--;
        }
        
        int start_idx = -1;
        int max_len = 0;
        for (auto p : scan) {
            if (p.second > 0 and start_idx < 0) {
                start_idx = p.first;
            } else {
                max_len = max(max_len, p.first - start_idx);
            }
        }
        
        return max_len + 1;
    }
};
