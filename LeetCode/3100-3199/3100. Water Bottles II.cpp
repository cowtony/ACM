class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drink = numBottles;  // Drink all first, then `numBottles` represent empty bottles
        while (numBottles >= numExchange) {
            numBottles -= numExchange++;
            drink++, numBottles++;  // Drink immediatly
        }
        return drink;
    }
};
