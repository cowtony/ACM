class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int res = 0;
        for (auto p : count) {
            res += p.second * (p.second - 1) / 2;
        }
        
        return res;
    }
};
