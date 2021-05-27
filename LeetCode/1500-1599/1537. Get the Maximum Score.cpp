class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        long score1 = 0, score2 = 0;
        while (i < nums1.size() and j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                score1 += nums1[i];
                i++;
            } else if (nums1[i] > nums2[j]) {
                score2 += nums2[j];
                j++;
            } else { // nums1[i] == nums2[j]
                score1 = score2 = max(score1, score2) + nums1[i];
                i++;
                j++;
            }
        }
        while (i < nums1.size()) {
            score1 += nums1[i++];
        }
        while (j < nums2.size()) {
            score2 += nums2[j++];
        }
        return max(score1, score2) % 1000000007;
    }
};
