class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        unordered_set<int> unique_nums;
        for (int num : nums) {
            unique_nums.insert(num);
        }
        int low = 1, high = unique_nums.size();
        
        long combination = (1 + nums.size()) * (long)nums.size() / 2;
        
        // binary serach the answer
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countWithinUnique(nums, mid) < (combination + 1) / 2) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
    
    // Get total number of subarrays which has distinct element <= distinct_target
    long countWithinUnique(const vector<int>& nums, int distinct_target) {
        long result = 0;
        unordered_map<int, int> count;
        for (int r = 0, l = 0; r < nums.size(); r++) {
            count[nums[r]]++;
                
            while (count.size() > distinct_target) {
                if (--count[nums[l]] == 0) {
                    count.erase(nums[l]);
                }
                l++;
            }
            
            result += r - l + 1;
        }
        return result;
    }
};
