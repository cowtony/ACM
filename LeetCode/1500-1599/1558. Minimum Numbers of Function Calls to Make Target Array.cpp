class Solution {
public:
    int minOperations(vector<int>& nums) {
        int max_double = 0;
        int res = 0;
        for (int num : nums) {
            auto [adds, doubles] = getOperation(num);
            res += adds;
            max_double = max(max_double, doubles);
        }
        
        return res + max_double;
    }
    
    tuple<int, int> getOperation(int num) {
        int adds = 0;
        int doubles = -1;
        while (num) {
            adds += num & 1;
            num >>= 1;
            doubles++;
        }
        return {adds, doubles};
    }
};
