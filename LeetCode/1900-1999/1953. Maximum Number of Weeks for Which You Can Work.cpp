class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = accumulate(milestones.begin(), milestones.end(), 0LL);
        int max_milestones = *max_element(milestones.begin(), milestones.end());

        if (max_milestones > sum - max_milestones + 1) {
            return (sum - max_milestones) * 2 + 1;
        } else {
            return sum;
        }
    }
};
