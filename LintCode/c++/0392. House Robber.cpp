class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        long long yes = 0;
        long long no = 0;
        long long all_max = yes;
        for (int num : A) {
            long long temp = yes;
            yes = no + num;
            no = max(no, temp);
            all_max = max(all_max, yes);
            all_max = max(all_max, no);
        }
        return all_max;
    }
};
