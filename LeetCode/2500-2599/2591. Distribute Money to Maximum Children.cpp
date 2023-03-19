class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;

        if (money < 0) {
            return -1;
        }
        int result = money / 7;
        if (result > children) {
            return children - 1;
        }
        if (result == children && money % 7 != 0) {
            return result - 1;
        }
        if (result == children - 1 && money % 7 == 3) {
            return result - 1;
        }
        return result;
    }
};
