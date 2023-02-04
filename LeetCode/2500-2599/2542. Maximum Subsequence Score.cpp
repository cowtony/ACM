class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> bundle(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            bundle[i] = {nums2[i], nums1[i]};
        }
        sort(bundle.rbegin(), bundle.rend());

        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0;
        long long result = 0;
        for (int i = 0; i < bundle.size(); i++) {
            sum += bundle[i].second;
            if (q.size() == k) {
                sum -= q.top();
                q.pop();
            }
            q.push(bundle[i].second);
            if (q.size() == k) {
                result = max(result, sum * bundle[i].first);
            }
            
        }
        return result;
    }
};