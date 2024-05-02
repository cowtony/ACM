class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> nums_set;
        for (int num : nums) {
            nums_set.insert(num);
        }

        for (auto it = nums_set.rbegin(); it != nums_set.rend(); it++) {
            if (nums_set.find(-(*it)) != nums_set.end()) {
                return *it;
            }
        }

        return -1;
    }
};
