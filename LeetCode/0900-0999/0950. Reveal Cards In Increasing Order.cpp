class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> que;
        for (int i = 0; i < deck.size(); i++) {
            que.push(i);
        }

        sort(deck.begin(), deck.end());
        vector<int> result(deck.size());
        for (int i = 0; i < deck.size(); i++) {
            result[que.front()] = deck[i];
            que.pop();
            que.push(que.front());
            que.pop();
        }

        return result;
    }
};
