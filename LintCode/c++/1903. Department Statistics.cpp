class Solution {
public:
    /**
     * @param employees: information of the employees
     * @param friendships: the friendships of employees
     * @return: return the statistics
     */
    vector<string> departmentStatistics(vector<string> &employees, vector<string> &friendships) {
        unordered_map<string, unordered_set<int>> ids;
        unordered_map<int, string> departments; // K
        for (string s : employees) {
            auto cells = split(s, ", ");
            int id = stoi(cells[0]);
            ids[cells[2]].insert(id);
            departments[id] = cells[2];
        }
        
        unordered_map<string, unordered_set<int>> friend_count;
        for (string s : friendships) {
            auto cells = split(s, ", ");
            int a = stoi(cells[0]);
            int b = stoi(cells[1]);
            string dep_a = departments.at(a);
            string dep_b = departments.at(b);
            if (dep_a != dep_b) {

                friend_count[dep_a].insert(a);
                friend_count[dep_b].insert(b);
            }
            
        }
        
        vector<string> ret;
        for (auto p : ids) {
            string dep = p.first;
            int friends = friend_count[dep].size();
            string s = dep + ": " + to_string(friends) + " of " + to_string(p.second.size());
            ret.push_back(s);
        }
        
        return ret;
    }
};
