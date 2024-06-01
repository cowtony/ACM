class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> distinct;
        for (int type : candyType) {
            distinct.insert(type);
        }
        return min(candyType.size() / 2, distinct.size());
    }
};
