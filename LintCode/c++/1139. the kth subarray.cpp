class Solution {
public:
    /**
     * @param a: an array
     * @param k: the kth
     * @return: return the kth subarray
     */
    long long thekthSubarray(vector<int> &a, long long k) {
        long long sum = 0;
        for (int num : a) {
            sum += num;
        }

        long long lo = 0, hi = sum;
        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;
            if (countSmaller(a, mid) < k) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
    
    long long countSmaller(vector<int> &a, long long target) {
        long long count = 0;
        long long sum = 0;
        for (int end = 0, start = 0; end < a.size(); end++) {
            sum += a[end];
            while (start <= end) {
                if (sum < target) {
                    count += end - start + 1;
                    break;
                } else {
                    sum -= a[start];
                    start++;
                }
            }
        }
        return count;
    }
};
