class Solution {
public:
    int rob(vector<int>& nums) {
        int yes = 0;
        int no = 0;
        int all_max = yes;
        for (int num : nums) {
            int temp = yes;
            yes = no + num;
            no = max(no, temp);
            all_max = max(all_max, yes);
            all_max = max(all_max, no);
        }
        return all_max;
    }
};
