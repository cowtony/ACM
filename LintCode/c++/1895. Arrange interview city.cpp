class Solution {
public:
    /**
     * @param cost: The cost of each interviewer
     * @return: The total cost of all the interviewers.
     */
    int TotalCost(vector<vector<int>> &cost) {
        // Assume send all people to city A first.
        
        vector<int> toB(cost.size()); // Cost of reroute a people from A to B.
        int total_cost = 0;
        for (int i = 0; i < cost.size(); i++) {
            total_cost += cost[i][0];
            toB[i] = cost[i][1] - cost[i][0];
        }
        
        // Move the lowest reroute half to city B.
        sort(toB.begin(), toB.end());
        for (int i = 0; i < cost.size() / 2; i++) {
            total_cost += toB[i];
        }
        
        return total_cost;
    }
};
