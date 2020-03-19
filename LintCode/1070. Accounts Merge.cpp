// LeetCode 721: https://leetcode.com/problems/accounts-merge/
class Solution {
public:
    /**
     * @param accounts: List[List[str]]
     * @return: return a List[List[str]]
     */
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        for (const vector<string>& account : accounts) {
            add(account[1], account[0]);
            for (int i = 2; i < account.size(); i++) {
                add(account[i], account[0]);
                connect(account[i], account[i - 1]);
            }
        }
        
        unordered_map<string, set<string>> heads;
        for (pair<string, string> node : father) {
            heads[root(node.first)].emplace(node.first);
        }
        vector<vector<string>> ans;
        for (pair<string, set<string>> p : heads) {
            vector<string> strs = {father[p.first]};
            for (const string& email : p.second) {
                strs.emplace_back(email);
            }
            ans.push_back(strs);
        }
        return ans;
    }
private:
    // Store user name at head node.
    unordered_map<string, string> father;
    
    void add(const string& email, const string& name) {
        if (father.find(email) == father.end()) {
            father[email] = name;
        }
    }
    void connect(const string& a, const string& b) {
        string ra = root(a);
        string rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
        }
    }
    string root(const string& email) {
        if (father[email].find("@") == string::npos) {
            return email;
        } else {
            return father[email] = root(father[email]);
        }
    }
};
