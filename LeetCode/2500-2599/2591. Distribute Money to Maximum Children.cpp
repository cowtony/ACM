class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;

        if (money < 0) {
            return -1;
        }
        if (money / 7 > children) {
            return children - 1;
        }
        if (money / 7 == children && money % 7 != 0) {
            return money / 7 - 1;
        }
        if (money / 7 == children - 1 && money % 7 == 3) {
            return money / 7 - 1;
        }
        return money / 7;
    }
};
