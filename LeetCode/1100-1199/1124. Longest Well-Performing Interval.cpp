class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> early_index;
        int extra_tiring = 0;
        int result = 0;
        for (int i = 0; i < hours.size(); i++) {
            extra_tiring += hours[i] > 8? 1 : -1;
            if (extra_tiring > 0) {
                result = i + 1;
            } else {
                if (early_index.find(extra_tiring) == early_index.end()) {
                    early_index[extra_tiring] = i;
                }
                if (early_index.find(extra_tiring - 1) != early_index.end()) {
                    result = max(result, i - early_index.at(extra_tiring - 1));
                }
            }
        }
        return result;
    }
};
