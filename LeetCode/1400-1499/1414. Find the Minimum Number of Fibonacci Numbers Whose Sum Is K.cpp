class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k == 0) {
            return 0;
        }
        int a = 1, b = 1;
        while (b <= k) {
            int next = a + b;
            a = b;
            b = next;
        }
        
        return 1 + findMinFibonacciNumbers(k - a);
    }
};
