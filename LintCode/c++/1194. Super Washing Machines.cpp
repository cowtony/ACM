class Solution {
public:
    /**
     * @param machines: an integer array representing the number of dresses in each washing machine from left to right on the line
     * @return: the minimum number of moves to make all the washing machines have the same number of dresses
     */
    int findMinMoves(vector<int> &machines) {
        int sum = 0;
        for (int dress : machines) {
            sum += dress;
        }
        if (sum % machines.size() != 0) {
            return -1;
        }
        int average = sum / machines.size();
        
        int moving = 0;
        int min_moving = INT_MIN;
        for (int dress : machines) {
            moving += dress - average;
            min_moving = max(min_moving, abs(moving));
            min_moving = max(min_moving, dress - average);
        }
        
        return min_moving;
    }
};
