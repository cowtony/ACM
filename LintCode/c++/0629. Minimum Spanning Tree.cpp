// LeetCode 1135: https://leetcode.com/problems/connecting-cities-with-minimum-cost/
/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */
class Solution {
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        sort(connections.begin(), 
             connections.end(), 
             [](const Connection& a, const Connection& b){
                 if (a.cost == b.cost) {
                     if (a.city1 == b.city1) {
                         return a.city2 < b.city2;
                     } else {
                         return a.city1 < b.city1;
                     }
                 } else {
                     return a.cost < b.cost;
                 }
             });
        vector<Connection> ans;
        for (Connection connection : connections) {
            if (father.find(connection.city1) == father.end()) {
                father[connection.city1] = connection.city1;
            }
            if (father.find(connection.city2) == father.end()) {
                father[connection.city2] = connection.city2;
            }
            string ra = root(connection.city1);
            string rb = root(connection.city2);
            if (ra != rb) {
                father[ra] = rb;
                ans.emplace_back(connection);
            }
        }
        if (father.size() == ans.size() + 1) {
            return ans;
        } else {
            return {};
        }
    }
    
private:
    unordered_map<string, string> father;
    
    string root(const string& a) {
        if (father[a] == a) {
            return a;
        } else {
            return father[a] = root(father[a]);
        }
    }
};
