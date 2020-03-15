class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pointer = 0;
        for (int i = 0; i < n; i++)
        {
            while (nums2[i] >= nums1[pointer] && pointer < m + i)
            {
                pointer++;
            }
            nums1.erase(nums1.begin() + nums1.size() - 1);
            nums1.insert(nums1.begin() + pointer, nums2[i]);
        }
    }
};
