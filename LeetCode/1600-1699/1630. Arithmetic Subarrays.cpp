class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result(l.size());
        for (int q = 0; q < l.size(); ++q) {
            vector<int> arithmetic;
            arithmetic.reserve(r[q] - l[q] + 1);
            for (int i = l[q]; i <= r[q]; ++i) {
                arithmetic.push_back(nums[i]);
            }
            sort(arithmetic.begin(), arithmetic.end());
            result[q] = isArithmetic(arithmetic);
        }
        return result;
    }

    bool isArithmetic(const vector<int>& nums) {
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] != nums[i - 1] - nums[i - 2]) {
                return false;
            }
        }
        return true;
    }
};
