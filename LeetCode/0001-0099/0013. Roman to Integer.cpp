class Solution {
public:
    int romanToInt(string s) {
        const unordered_map<char, int> kMap = {{'I', 1},
                                               {'V', 5},
                                               {'X', 10},
                                               {'L', 50},
                                               {'C', 100},
                                               {'D', 500},
                                               {'M', 1000},};
        vector<int> series;
        for (char c : s) {
            series.push_back(kMap.at(c));
        }
        
        int result = 0;
        for (int i = 0; i < series.size(); i++) {
            if (i < series.size() - 1 && series[i] < series[i + 1]) {
                result += series[i + 1] - series[i];
                i++;
            }
            else {
                result += series[i];
            }
        }
        
        return result;
    }
};
