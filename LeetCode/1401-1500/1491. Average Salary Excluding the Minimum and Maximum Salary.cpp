class Solution {
public:
    double average(vector<int>& salary) {
        int min_s = INT_MAX, max_s = INT_MIN, sum = 0;
        for (int s : salary) {
            sum += s;
            min_s = min(min_s, s);
            max_s = max(max_s, s);
        }
        
        return (sum - min_s - max_s) / double(salary.size() - 2);
    }
};
