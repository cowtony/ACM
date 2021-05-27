class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> nums;
        for (int a : arr) {
            nums.insert(a);
        }
        int count = 0;
        for (int a : arr) {
            if (nums.find(a + 1) != nums.end()) {
                count++;
            }
        }
        return count;
    }
};
