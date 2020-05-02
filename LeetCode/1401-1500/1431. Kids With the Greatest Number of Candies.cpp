class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ret;
        int max_candie = INT_MIN;
        for (int num : candies) {
            max_candie = max(max_candie, num);
        }
        for (int num : candies) {
            ret.push_back(num + extraCandies >= max_candie);
        }
        return ret;
    }
};
