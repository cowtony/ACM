class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        int end = -1;
        int count = 0;
        for (auto& range : ranges) {
            if (range[0] > end) {
                count++;
            }
            end = max(end, range[1]);
        }
        return power2(count);
    }
    
    int power2(int n) {
        int result = 1;
        while (n--) {
            result = (result * 2) % 1000000007;
        }
        return result;
    }
};
