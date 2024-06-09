class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> reminder_count;
        reminder_count[0] = 1;

        int sum = 0, result = 0;
        for (int num : nums) {
            sum += num;
            result += reminder_count[(sum % k + k) % k]++;
        }
        return result;
    }
};
