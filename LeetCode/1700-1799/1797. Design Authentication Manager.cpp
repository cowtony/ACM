class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        kTimeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        eraseExpired(currentTime);

        active_tokens_[currentTime + kTimeToLive].insert(tokenId);
        its_[tokenId] = active_tokens_.find(currentTime + kTimeToLive);
    }
    
    void renew(string tokenId, int currentTime) {
        eraseExpired(currentTime);

        if (its_.find(tokenId) == its_.end()) {
            return;
        }
        its_.at(tokenId)->second.erase(tokenId);
        generate(tokenId, currentTime);
    }
    
    int countUnexpiredTokens(int currentTime) {
        eraseExpired(currentTime);
        return its_.size();
    }

private:
    int kTimeToLive;
    map<int, unordered_set<string>> active_tokens_; // <expire_time, token_ids>
    unordered_map<string, map<int, unordered_set<string>>::iterator> its_;

    void eraseExpired(int currentTime) {
        while (!active_tokens_.empty() && active_tokens_.begin()->first <= currentTime) {
            for (const string& token_id : active_tokens_.begin()->second) {
                its_.erase(token_id);
            }
            active_tokens_.erase(active_tokens_.begin());
        }
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
