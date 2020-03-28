struct TweetNode {
    TweetNode(int t, int tweet) : time(t), tweet_id(tweet) {}
    int time;
    int tweet_id;
    TweetNode* next = nullptr;
    TweetNode* pre = nullptr;
};

struct MyCompare {
  bool operator()(TweetNode* a, TweetNode* b) {
    return a->time < b->time;
  }
};

class LinkedList {
public:
    TweetNode* head = nullptr;
    TweetNode* tail = nullptr;
    int length = 0;
    
    void push_back(TweetNode node) {
        if (tail == nullptr) {
            TweetNode* n = new TweetNode(node);
            head = n;
            tail = n;
        } else {
            tail->next = new TweetNode(node);
            tail = tail->next;
        }
        length++;
    }
    void push_front(TweetNode node) {
        TweetNode* n = new TweetNode(node);
        n->next = head;
        head = n;
        length++;
    }
    void pop_back() {
        if (tail) {
            TweetNode* temp = tail;
            tail = tail->pre;
            length--;
            delete temp;
            if (tail == nullptr) {
                head = nullptr;
            }
        }
    }
};

// Pull model.
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // Create new user if not exist.
        follows[userId].insert(userId);
        posts[userId].push_front(TweetNode(time++, tweetId));
        if (posts[userId].length > 10) {
            posts[userId].pop_back();
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        priority_queue<TweetNode*, vector<TweetNode*>, MyCompare> pq;
        for (int followee : follows[userId]) {
            if (posts[followee].head) {
                pq.push(posts[followee].head);
            }
        }
        for (int i = 0; i < 10 and !pq.empty(); i++) {
            TweetNode* node = pq.top();
            pq.pop();
            ret.push_back(node->tweet_id);
            node = node->next;
            if (node) {
                pq.push(node);
            }
        }
        return ret;
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
    int time = 0; // Internal clock.
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, LinkedList> posts; // Key = userID, Value = list of <time, tweetID> nodes.
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
