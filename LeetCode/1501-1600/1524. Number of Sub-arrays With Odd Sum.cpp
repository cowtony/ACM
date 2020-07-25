class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int dp_odd = 0, dp_even = 0; // Store the number of odd/even sum ending with current index. (memory compressed)
        int res = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 0) {
                dp_even++;
            } else {
                swap(dp_odd, dp_even);
                dp_odd++;
            }
            res = (res + dp_odd) % 1000000007;
        }
        
        return res;
    }
};
