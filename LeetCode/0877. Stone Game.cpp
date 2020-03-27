class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Since piles.size() is even, the first player can first find out even piles sum larger or odd piles larger.
        // Then he can always select the even pile or odd pile no matter what the other choose.
        // Under this strategy the first player always wins.
        return true;
    }
};
