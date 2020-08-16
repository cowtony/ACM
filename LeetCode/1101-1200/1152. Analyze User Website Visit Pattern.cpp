class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>> user_visits;
        for (int i = 0; i < username.size(); i++) {
            user_visits[username[i]][timestamp[i]] = website[i];
        }
        
        set<vector<string>> three_sequences;
        for (const auto& p : user_visits) {
            pick_3_sequence(p.second, three_sequences, p.second.begin());
        }
        
        int max_user = 0;
        vector<string> res;
        for (const auto& three_sequence : three_sequences) {
            int count = 0;
            for (const auto& p : user_visits) {
                if (hasMatch(three_sequence, p.second)) {
                    count++;
                }
            }
            if (count > max_user) {
                max_user = count;
                res = three_sequence;
            }
        }
        
        return res;
    }
    
    void pick_3_sequence(const map<int, string>& input, set<vector<string>>& three_sequences, map<int, string>::const_iterator it, vector<string> path = {}) {
        if (path.size() == 3) {
            three_sequences.insert(path);
            return;
        }
        while (it != input.end()) {
            path.push_back(it->second);
            pick_3_sequence(input, three_sequences, ++it, path);
            path.pop_back();
        }
    }
    
    bool hasMatch(const vector<string>& three_sequence, const map<int, string>& websites) {
        int i = 0;
        for (auto p : websites) {
            if (p.second == three_sequence[i]) {
                i++;
                if (i >= 3) {
                    return true;
                }
            }
        }
        return false;
    }
};
