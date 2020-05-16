/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
struct TweetNode {
    TweetNode(int t, int user, string s) : time(t) {
        tweet = Tweet::create(user, s);
    }
    int time;
    Tweet tweet;
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

class MiniTwitter {
public:
    MiniTwitter() {
        // do intialization if necessary
    }

    /*
     * @param user_id: An integer
     * @param tweet_text: a string
     * @return: a tweet
     */
     Tweet postTweet(int user_id, string &tweet_text) {
        // Create new user if not exist.
        follows[user_id].insert(user_id);
        TweetNode t(time++, user_id, tweet_text);
        posts[user_id].push_front(t);
        if (posts[user_id].length > 10) {
            posts[user_id].pop_back();
        }
        return t.tweet;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new feeds recently and sort by timeline
     */
    vector<Tweet> getNewsFeed(int user_id) {
        priority_queue<TweetNode*, vector<TweetNode*>, MyCompare> pq;
        for (int followee : follows[user_id]) {
            if (posts[followee].head) {
                pq.push(posts[followee].head);
            }
        }
        vector<Tweet> ret;
        for (int i = 0; i < 10 and !pq.empty(); i++) {
            TweetNode* node = pq.top();
            pq.pop();
            ret.push_back(node->tweet);
            node = node->next;
            if (node) {
                pq.push(node);
            }
        }
        return ret;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new posts recently and sort by timeline
     */
    vector<Tweet> getTimeline(int user_id) {
        vector<Tweet> ret;
        TweetNode* node = posts[user_id].head;
        for (int i = 0; i < 10 and node; i++) {
            ret.push_back(node->tweet);
            node = node->next;
        }
        return ret;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int from_user_id, int to_user_id) {
        follows[from_user_id].insert(to_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int from_user_id, int to_user_id) {
        // Cannot unfollow yourself.
        if (from_user_id != to_user_id) {
            follows[from_user_id].erase(to_user_id);
        }
    }
    
private:
    int time = 0; // Internal clock.
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, LinkedList> posts; // Key = userID, Value = list of <time, tweetID> nodes.
};
