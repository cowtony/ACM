class Solution {
public:
    int minMaxDifference(int num) {
        string num_str = to_string(num);

        string max_str = num_str;
        for (char c : num_str) {
            if (c < '9') {
                replace(max_str.begin(), max_str.end(), c, '9');
                break;
            }
        }

        string min_str = num_str;
        replace(min_str.begin(), min_str.end(), num_str.front(), '0');
        
        return stoi(max_str) - stoi(min_str);
    }
};
