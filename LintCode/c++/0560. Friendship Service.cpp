class FriendshipService {
public:
    FriendshipService() {
        // do intialization if necessary
    }

    /*
     * @param user_id: An integer
     * @return: all followers and sort by user_id
     */
    vector<int> getFollowers(int user_id) {
        return {followers[user_id].begin(), followers[user_id].end()};
    }

    /*
     * @param user_id: An integer
     * @return: all followings and sort by user_id
     */
    vector<int> getFollowings(int user_id) {
        return {followings[user_id].begin(), followings[user_id].end()};
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int to_user_id, int from_user_id) {
        followings[from_user_id].insert(to_user_id);
        followers[to_user_id].insert(from_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int to_user_id, int from_user_id) {
        followings[from_user_id].erase(to_user_id);
        followers[to_user_id].erase(from_user_id);
    }
private:
    map<int, set<int>> followers;
    map<int, set<int>> followings;
};
