class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int count = 0;
        int winner = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > winner) {
                count = 1;
                winner = arr[i];
            } else { // arr[i] < winner
                count++;
            }
            if (count == k) {
                return winner;
            }
        }
        return winner;
    }
};
