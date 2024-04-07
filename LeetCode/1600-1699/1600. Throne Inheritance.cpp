class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        kingName_ = kingName;
        children_[kingName];
    }
    
    void birth(string parentName, string childName) {
        children_[childName];
        children_[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead_.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> result;
        dfs(kingName_, result);
        return result;
    }

private:
    string kingName_;
    unordered_map<string, vector<string>> children_;
    unordered_set<string> dead_;

    void dfs(string name, vector<string>& curOrder) {
        if (dead_.find(name) == dead_.end()) {
            curOrder.push_back(name);
        }
        for (const string& child : children_.at(name)) {
            dfs(child, curOrder);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
