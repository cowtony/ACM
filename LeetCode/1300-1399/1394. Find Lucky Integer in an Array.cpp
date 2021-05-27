class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int num : arr) {
            m[num]++;
        }
        int ret = -1;
        for (auto p : m) {
            if (p.first == p.second) {
                ret = max(ret, p.first);
            }
        }
        return ret;
    }
};
