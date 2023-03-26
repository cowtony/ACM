class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (!canMinusP(nums[i], nums[i + 1])) {
                return false;
            }
        }
        return true;
    }
    
    bool canMinusP(int& num, int target) {
        if (num < target) {
            return true;
        }
        for (int p = target - num + 1; p < num; p++) {
            if (isPrime(p) && num - p < target) {
                num -= p;
                return true;
            }
        }
        
        return false;
    }
    
    bool isPrime(int p) {
        if (p <= 2) {
            return p == 2;
        }
        if (p % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= p; i += 2) {
            if (p % i == 0) {
                return false;
            }
        }
        return true;
    }
};
