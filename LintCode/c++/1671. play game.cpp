class Solution {
public:
    /**
     * @param A: 
     * @return: nothing
     */
    long long playGames(vector<int> &A) {
        long long sum = 0;
        int maximum = INT_MIN;
        for (int a : A) {
            sum += a;
            maximum = max(maximum, a);
        }
        
        int res = (sum - 1) / (A.size() - 1) + 1;
        return max(res, maximum);
    }
};
