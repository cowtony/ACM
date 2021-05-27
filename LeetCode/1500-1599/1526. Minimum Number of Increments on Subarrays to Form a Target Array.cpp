class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = 0, pre = 0;
        for (int num : target) {
            res += max(num - pre, 0);
            pre = num;
        }
        return res;
    }
};
