class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        return {helper(nums1, nums2), helper(nums2, nums1)};
    }

    int helper(const vector<int>& nums1, const vector<int>& nums2) {
        int count = 0;
        int i = 0;
        for (int num : nums1) {
            while (i < nums2.size() && num > nums2[i]) {
                i++;
            }
            if (i == nums2.size()) {
                break;
            }
            if (num == nums2[i]) {
                count++;
            }
        }
        return count;
    }
};
