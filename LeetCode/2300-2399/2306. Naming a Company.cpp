class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> group[26];
        for (const string& idea : ideas) {
            group[idea.front() - 'a'].insert(idea.substr(1));
        }

        long long result = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                long long c1 = 0, c2 = 0;                
                for (const string& suffix : group[i]) {
                    if (group[j].find(suffix) == group[j].end()) {
                        c1++;
                    }
                }
                for (const string& suffix : group[j]) {
                    if (group[i].find(suffix) == group[i].end()) {
                        c2++;
                    }
                }
                result += c1 * c2;
            }
        }
        return result * 2;
    }
};
