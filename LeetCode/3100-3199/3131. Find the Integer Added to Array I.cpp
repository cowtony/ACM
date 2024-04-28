class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int x1 = *min_element(nums1.begin(), nums1.end());
        int x2 = *min_element(nums2.begin(), nums2.end());
        return x2 - x1;
    }
};
