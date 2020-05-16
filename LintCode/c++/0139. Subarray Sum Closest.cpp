class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        map<int, int> m;
        m[0] = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m.find(sum) != m.end()) {
                return {m[sum], i};
            }
            m[sum] = i + 1;
        }
        
        int min_diff = INT_MAX;
        vector<int> ret;
        auto pre = m.begin();
        auto it = m.begin();
        for (++it; it != m.end(); it++) {
            if (it->first - pre->first <= min_diff) {
                min_diff = it->first - pre->first;
                ret = {pre->second, it->second};
                if (ret[0] > ret[1]) {
                    swap(ret[0], ret[1]);
                }
                ret[1]--;
            }
            pre = it;
        }
        return ret;
    }
};
