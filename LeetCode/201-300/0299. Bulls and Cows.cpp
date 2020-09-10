class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> count(10, 0);
        for (char c : secret) {
            count[c - '0']++;
        }
            
        int cows = 0;
        for (char c : guess) {
            if (count[c - '0']-- > 0) {
                cows++;
            }
        }
        
        int bulls = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows - bulls) + "B";
    }
};
