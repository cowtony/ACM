class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int p1 = 0, p2 = 0;
        while (p1 < nums1.size() || p2 < nums2.size()) {
            if (p1 == nums1.size()) {
                result.push_back({nums2[p2][0], nums2[p2++][1]});
            } else if (p2 == nums2.size()) {
                result.push_back({nums1[p1][0], nums1[p1++][1]});
            } else if (nums1[p1][0] < nums2[p2][0]) {
                result.push_back({nums1[p1][0], nums1[p1++][1]});
            } else if (nums1[p1][0] > nums2[p2][0]) {
                result.push_back({nums2[p2][0], nums2[p2++][1]});
            } else {
                result.push_back({nums1[p1][0], nums1[p1++][1] + nums2[p2++][1]});
            }
        }
        return result;
    }
};
