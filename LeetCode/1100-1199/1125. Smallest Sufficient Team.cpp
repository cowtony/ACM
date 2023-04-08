class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skill_map;
        for (int i = 0; i < req_skills.size(); ++i) {
            skill_map[req_skills[i]] = i;
        }

        vector<short> people_skills(people.size(), 0);
        for (int i = 0; i < people.size(); ++i) {
            for (const string& skill : people[i]) {
                if (skill_map.count(skill) > 0) {
                    people_skills[i] |= 1 << skill_map[skill];
                }
            }
        }

        unordered_map<short, vector<int>> dp;
        dp.reserve(1 << req_skills.size());
        dp[0] = {};
        for (int i = 0; i < people.size(); ++i) {
            for (const auto& [skill, team] : dp) {
                short final_skill = skill | people_skills[i];
                if (dp.find(final_skill) == dp.end() || dp[final_skill].size() > team.size() + 1) {
                    dp[final_skill] = team;
                    dp[final_skill].push_back(i);
                }
            }
        }
        return dp[(1 << req_skills.size()) - 1];
    }
};
