class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            for (char c : to_string(num)) {
                result.push_back(c - '0');
            }
        }
        return result;
    }
};
