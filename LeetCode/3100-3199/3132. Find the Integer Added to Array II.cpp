class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> possible;
        for (int start = 0; start <= 2; start++) {
            // keep nums1[0]:
            // remove nums1[0] and keep nums1[1]:
            // remove nums1[0] and nums1[1]:
            if (checkMatch(nums1, nums2, start)) {
                possible.push_back(nums2[0] - nums1[start]);
            }
        }
        
        return *min_element(possible.begin(), possible.end());
    }

    bool checkMatch(const vector<int>& nums1, const vector<int>& nums2, int start) {
        int diff = nums2[0] - nums1[start];
        int mismatch = 0;
        for (int i = start + 1, j = 1; i < nums1.size() && j < nums2.size(); i++, j++) {
            if (nums2[j] - nums1[i] != diff) {
                mismatch++;
                j--;
            }
            if (mismatch > 2 - start) {
                return false;
            }
        }
        return true;
    }
};
