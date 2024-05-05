class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        long max_value = *max_element(nums.begin(), nums.end());
        long min_value = *min_element(nums.begin(), nums.end());
        
        long increment = max_value * nums.size() - sum;
        // Scenarios where cost2 would never be needed:
        if (cost2 >= 2 * cost1 || nums.size() <= 2) {
            return (cost1 * increment) % 1000000007;
        }
        
        long biggest_gap = max_value - min_value;
        long min_cost = LONG_MAX;

        if (cost2 > cost1) { // In this scenario, no need to reach the target more than `max_value`:
            if (2 * biggest_gap >= increment) {
                min_cost = min(min_cost, (cost2 * (increment - biggest_gap) + cost1 * (2 * biggest_gap - increment)));
            } else {
                min_cost = min(min_cost, cost2 * (increment / 2) + cost1 * (increment % 2));
            }
            return min_cost % 1000000007;
        }
        
        // Starting to try to reach the max_value, max_value + 1, etc:
        // This is for the case such as [1, 14, 15], where several operation_1 is still needed.
        // The total iteration of this loop is: `(2 * biggest_gap - increment) / (nums.size() - 2) + 1`
        while (2 * biggest_gap >= increment) {
            min_cost = min(min_cost, (cost2 * (increment - biggest_gap) + cost1 * (2 * biggest_gap - increment)));
            biggest_gap++;
            increment += nums.size();
        }
                    
        // Now it satisfy `2 * biggest_gap < increment`:
        // This scenario only at most 1 operation_1.
        min_cost = min(min_cost, cost2 * (increment / 2) + cost1 * (increment % 2));
        if (increment % 2 == 1 && nums.size() % 2 == 1) {
            increment += nums.size();  // Increment the max_value target by 1 so that usage of cost1 could be fliped.
            min_cost = min(min_cost, cost2 * (increment / 2) + cost1 * (increment % 2));
        }
        
        return min_cost % 1000000007;
    }
};
