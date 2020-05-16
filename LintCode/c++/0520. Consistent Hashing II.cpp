class Solution {
public:
    /*
     * @param n: a positive integer
     * @param k: a positive integer
     * @return: a Solution object
     */
    static Solution create(int n, int k) {
        Solution s;
        s.n_ = n;
        s.k_ = k;
        return s;
    }

    /*
     * @param machine_id: An integer
     * @return: a list of shard ids
     */
    vector<int> addMachine(int machine_id) {
        vector<int> ret;
        for (int i = 0; i < k_; i++) {
            int hash;
            do {
                hash = rand() % n_;
            } while (machines_.find(hash) != machines_.end());
            
            machines_[hash] = machine_id;
            ret.emplace_back(hash);
        }
        return ret;
    }

    /*
     * @param hashcode: An integer
     * @return: A machine id
     */
    int getMachineIdByHashCode(int hashcode) {
        auto it = machines_.lower_bound(hashcode % n_);
        if (it == machines_.end()) {
            it = machines_.begin();
        }
        return it->second;
    }

private:
    int n_;
    int k_;
    map<int64_t, int> machines_;
};
