class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<int, int, greater<int>> diff_count;
        for (int i = 0; i < nums1.size(); i++) {
            diff_count[abs(nums1[i] - nums2[i])]++;
        }

        int k = k1 + k2;
        while (k > 0 && !diff_count.empty()) {
            auto it = diff_count.begin();
            auto it2 = next(it, 1);
            int next_high = it2 != diff_count.end()? it2->first : 0;
            int decease = min(k / it->second, it->first - next_high);
            if (decease == it->first - next_high || decease > 0) {
                diff_count[it->first - decease] += it->second;
                k -= decease * it->second;
                diff_count.erase(it);
            } else {
                diff_count[it->first - 1] += k;
                diff_count[it->first] -= k;
                k = 0;
            }
        }

        long long result = 0;
        for (auto [diff, count] : diff_count) {
            result += (long long)count * diff * diff;
        }
        return result;
    }
};
