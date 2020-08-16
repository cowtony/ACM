class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int max_vote = 0;
        int max_person;
        for (int i = 0; i < times.size(); i++) {
            votes[persons[i]]++;
            if (votes[persons[i]] >= max_vote) {
                max_vote = votes[persons[i]];
                max_person = persons[i];
            }
            highest_at_time[times[i]] = max_person;
        }
    }
    
    int q(int t) {
        auto it = highest_at_time.lower_bound(t);  // O(log n)
        if (it == highest_at_time.end() or it->first != t) {
            it--;
        }
        return it->second;
    }
    
private:
    unordered_map<int, int> votes;
    map<int, int> highest_at_time;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
