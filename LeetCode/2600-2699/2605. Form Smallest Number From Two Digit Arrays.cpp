class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<bool> digit(10, false);
        for (int d : nums1) {
            digit[d] = true;
        }
        for (int d : nums2) {
            if (digit[d]) {
                return d;
            }
        }
        
        if (nums1[0] > nums2[0]) {
            swap(nums1[0], nums2[0]);
        }
        return nums1[0] * 10 + nums2[0];
    }
};
