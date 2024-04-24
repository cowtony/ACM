class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int fuel = 0;
        while (mainTank >= 5 && additionalTank > 0) {
            int transfer = min(mainTank / 5, additionalTank);
            fuel += transfer * 5;
            mainTank -= transfer * 5;

            mainTank += transfer;
            additionalTank -= transfer;
        }
        fuel += mainTank;

        return fuel * 10;
    }
};
