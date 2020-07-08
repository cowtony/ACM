class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        
        for (const auto& edge : transactions) {
            balance[edge.at(0)] -= edge.at(2);
            if (balance[edge.at(0)] == 0) {
                balance.erase(edge.at(0));
            }
            balance[edge.at(1)] += edge.at(2);
            if (balance[edge.at(1)] == 0) {
                balance.erase(edge.at(1));
            }
        }
        
        if (balance.empty()) {
            return 0;
        }
        
        // For n unbalanced nodes, we only need maximum n-1 transfers to balance them.
        // But the minimum edges may caused by more than 1 groups that sum to 0.
        // The problem now is, how many groups in an array that sum to zero?
        vector<int> nums;
        for(const auto& p : balance) {
            if (p.second != 0) {
                nums.push_back(p.second);
            }
        }
        
        vector<int> used;
        dfsTraversal(nums, used, 0, 0); // Get all possible combinitions.
        
        // Then DFS to find out maximum groups, with memorize.
        return balance.size() - maxGroups(0);
    }
    
    vector<vector<int>> groups;
    void dfsTraversal(vector<int>& nums, vector<int>& used, int idx, int sum) {
        for (int i = idx; i < nums.size(); i++) {
            used.push_back(i);
            dfsTraversal(nums, used, i + 1, sum + nums.at(i));
            used.pop_back();
        }
        if (sum == 0 and !used.empty()) {
            groups.push_back(used);
        }
    }
    
    // Momerize DFS search.
    unordered_map<int, int> dp;
    int maxGroups(int index) {
        if (dp.find(index) != dp.end()) {
            return dp.at(index);
        }
        
        int max_num = 1;
        for (int i = index + 1; i < groups.size(); i++) {
            // if i is subarray of index, i must be after index.
            if (isSubArray(groups[index], groups[i])) {
                max_num = max(max_num, 1 + maxGroups(i));
            }
        }
        dp[index] = max_num;
        return max_num;
    }
    
    // Util functions.
    bool isSubArray(const vector<int>& a, const vector<int>& b) {
        int i = 0, j = 0;
        while (j < b.size()) {
            if (i >= a.size()) {
                return false;
            }
            if (a[i] < b[j]) {
                i++;
            } else if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                return false;
            }
        }
        return true;
    }
};
