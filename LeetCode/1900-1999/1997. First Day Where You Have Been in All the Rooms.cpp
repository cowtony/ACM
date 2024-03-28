class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        vector<long> dp1(nextVisit.size(), 0);
        vector<long> dp2(nextVisit.size(), 0);

        dp1[0] = 0;
        dp2[0] = 1;

        for (int i = 1; i < nextVisit.size(); i++) {
            dp1[i] = (dp2[i - 1] + 1) % 1000000007;
            dp2[i] = (dp1[i] + dp1[i] - dp1[nextVisit[i]] + 1 + 1000000007) % 1000000007;
        }

        return dp1.back();
    }
};
