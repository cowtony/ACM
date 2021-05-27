class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans += fourDivisors(num);
        }
        return ans;
    }
    int fourDivisors(int num) {
        int i = 2;
        int count = 2;
        int sum = 1 + num;
        while (i * i < num) {
            if (num % i == 0) {
                count += 2;
                sum += i + num / i;
            }
            i++;
        }
        if (i * i == num) {
            count++;
            sum += i;
        }
        if (count > 4) {
            return 0;
        }
        return count == 4? sum : 0;
    }
};
