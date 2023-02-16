class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int result = INT_MAX;
        vector<int> bit_count(32, 0);
        int l = 0, r = -1;
        while (r < int(arr.size())) {
            int num = getNumber(bit_count, r - l + 1);
            result = min(result, abs(target - num));
            if (num >= target) {
                if (++r < arr.size()) {
                    addNumber(bit_count, arr[r]);
                } 
            } else {
                minusNumber(bit_count, arr[l]);
                l++;
            }
        }
        return result;
    }

    void addNumber(vector<int>& bit_count, int num) {
        int i = 0;
        while (num) {
            bit_count[i++] += num % 2;
            num >>= 1;
        }
    }

    void minusNumber(vector<int>& bit_count, int num) {
        int i = 0;
        while (num) {
            bit_count[i++] -= num % 2;
            num >>= 1;
        }
    }

    // O(32)
    int getNumber(const vector<int>& bit_count, int size) {
        if (size <= 0) {
            return INT_MAX;
        }
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            result <<= 1;
            if (bit_count[i] == size) {
                result += 1;
            }
        }
        return result;
    }
};
