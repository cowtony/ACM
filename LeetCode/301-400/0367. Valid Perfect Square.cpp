class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1, end = 46340;
        while (start < end) {
            int mid = (start + end) / 2;
            if (mid * mid < num) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return end * end == num;
    }
};
