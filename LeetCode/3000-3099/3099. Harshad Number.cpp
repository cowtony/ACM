class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, num = x;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return x % sum == 0? sum : -1;
    }
};
