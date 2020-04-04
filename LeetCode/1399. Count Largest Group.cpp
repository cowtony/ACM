class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        for (int i = 1; i <= n; i++) {
            m[digitSum(i)]++;
        }
        
        int max_size = 0;
        for (auto [k, v] : m) {
            max_size = max(max_size, v);
        }
        
        int count = 0;
        for (auto [k, v] : m) {
            if (v == max_size) {
                count++;
            }
        }
        return count;
    }
    
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};
