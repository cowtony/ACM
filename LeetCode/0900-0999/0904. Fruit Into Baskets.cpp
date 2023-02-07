// Sliding window, O(n)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruit_count;
        int result = 0;
        for (int left = 0, right = 0; right < fruits.size(); right++) {
            fruit_count[fruits[right]]++;
            while (fruit_count.size() > 2) {
                if (--fruit_count[fruits[left]] == 0) {
                    fruit_count.erase(fruits[left]);
                }
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};