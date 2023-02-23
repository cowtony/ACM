class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> count_distinct;
        for (int num : nums) {
            if (num > 0) {
                count_distinct.insert(num);
            }
        }
        return count_distinct.size();
    }
};
