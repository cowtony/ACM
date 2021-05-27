class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follows[userId].insert(userId);  // Create new user if not exist.
        
        posts[userId].push_front({time++, tweetId});
        if (posts[userId].size() > 10) {
            posts[userId].pop_back();
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        struct Node {
            list<Tweet>::const_iterator begin, end;
            bool operator < (const Node& n) const {
                return begin->time < n.begin->time;
            }
        };
        priority_queue<Node> pq;
        
        for (int followee : follows[userId]) {
            if (posts[followee].begin() != posts[followee].end()) {
                pq.push({posts[followee].begin(), posts[followee].end()});
            }
        }
        
        vector<int> res;
        for (int i = 0; i < 10 and !pq.empty(); i++) {
            auto [begin, end] = pq.top();
            pq.pop();
            res.push_back(begin->tweet_id);
            if (++begin != end) {
                pq.push({begin, end});
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        // Cannot unfollow yourself.
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
    
private:
    struct Tweet {
        int time;
        int tweet_id;
    };
    
    int time = 0; // Internal clock.
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, list<Tweet>> posts; // Key = userID, Value = list of <time, tweetID> nodes.
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
