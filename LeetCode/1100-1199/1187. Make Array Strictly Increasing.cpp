class Solution {
public:
    struct DefaultValue {
        int val = 10000000;
    };

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());

        map<int, DefaultValue> dp;  // dp[i] = j means the minimum steps is j to make the array's last value equal to i.
        dp[INT_MIN].val = 0;
        for (int num : arr1) {
            map<int, DefaultValue> next;
            int j = 0;
            for (auto it = dp.begin(); it != dp.end(); ++it) {
                while (j < arr2.size() && arr2[j] <= it->first) {
                    ++j;
                }
                if (j < arr2.size()) {
                    next[arr2[j]].val = min(next[arr2[j]].val, it->second.val + 1);
                }
                if (it->first < num) {
                    next[num].val = min(next[num].val, it->second.val);
                }
            }
            dp = next;
        }
        
        auto it = min_element(dp.begin(), dp.end(), [](auto a, auto b) {
            return a.second.val < b.second.val;
        });
        return dp.empty()? -1 : it->second.val;
    }
};
