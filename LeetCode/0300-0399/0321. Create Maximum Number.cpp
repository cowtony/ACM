class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        for (int len1 = max(0, k - int(nums2.size())), len2 = k - len1;
             len1 <= nums1.size() && len2 >= 0; len1++, len2--) {

            vector<int> result1 = maxNumber(nums1, len1);
            vector<int> result2 = maxNumber(nums2, len2);
            result = max(result, mergeSort(result1, result2));
        }
        return result;
    }

    vector<int> maxNumber(const vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            while (!result.empty() && nums[i] > result.back() && nums.size() - i > k - result.size()) {
                result.pop_back();
            }
            if (result.size() < k) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }

    vector<int> mergeSort(const vector<int>& nums1, const vector<int>& nums2) {
        auto greater = [&nums1, &nums2](int p1, int p2) -> bool {
            while (p1 < nums1.size() && p2 < nums2.size() && nums1[p1] == nums2[p2]) {
                p1++, p2++;
            }
            return p1 < nums1.size() && (p2 == nums2.size() || nums1[p1] > nums2[p2]);
        };

        vector<int> result;
        int p1 = 0, p2 = 0;
        while (result.size() < nums1.size() + nums2.size()) {
            result.push_back(greater(p1, p2)? nums1[p1++] : nums2[p2++]);
        }
        return result;
    }
};
