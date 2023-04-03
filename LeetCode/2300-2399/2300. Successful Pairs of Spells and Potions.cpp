class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> pairs(spells.size());
        for (int i = 0; i < spells.size(); ++i) {
            int idx = binarySearch(potions, spells[i], success);
            pairs[i] = potions.size() - idx;
        }
        return pairs;
    }

    int binarySearch(const vector<int>& potions, long long spell, long long success) {
        int left = 0, right = potions.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (potions[mid] * spell < success) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
