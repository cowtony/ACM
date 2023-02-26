class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<string, int> dp;
        dp[GetInitialState(letters)] = 0;
        int result = 0;
        for (const string& word : words) {
            int value = 0;
            for (char c : word) {
                value += score[c - 'a'];
            }
            auto dp_temp = dp;
            for (const auto [state, max_score] : dp) {
                string new_state = GetNewState(state, word);
                if (new_state.length() != 26) {
                    continue;
                }
                dp_temp[new_state] = max(dp_temp[new_state], max_score + value);
                result = max(result, dp_temp[new_state]);
            }
            dp = dp_temp;
        }
        return result;
    }
    
    string GetInitialState(const vector<char>& letters) {
        string state(26, char(1));
        for (char c : letters) {
            state[c - 'a']++;
        }
        return state;
    }
    string GetNewState(string state, string word) {
        for (char c : word) {
            if (state[c - 'a'] <= 1) {
                return "INVALID";
            }
            state[c - 'a']--;
        }
        return state;
    }

};
