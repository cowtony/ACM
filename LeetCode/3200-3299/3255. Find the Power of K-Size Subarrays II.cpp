class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;

        int max_consecutive = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] - nums[ i - 1] == 1) {
                max_consecutive++;
            } else {
                max_consecutive = 1;
            }

            if (i >= k - 1) {
                if (max_consecutive >= k) {
                    result.push_back(nums[i]);
                } else {
                    result.push_back(-1);
                }
            }
        }
        return result;
    }
};
