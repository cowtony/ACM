class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people(names.size());
        for (int i = 0; i < names.size(); ++i) {
            people[i] = {heights[i], names[i]};
        }
        sort(people.rbegin(), people.rend());

        for (int i = 0; i < names.size(); ++i) {
            names[i] = people[i].second;
        }
        return names;
    }
};
