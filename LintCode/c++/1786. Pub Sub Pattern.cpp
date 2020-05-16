/* Definition of PushNotification
 * class PushNotification {
 * public:
 *     void static notify(int user_id, string message) 
 *  };
 */
class PubSubPattern {
public:
	PubSubPattern() {
		// initialize your data structure here.
	}
	/**
	* @param channel:
	* @param user_id:
	* @return: nothing
	*/
	void subscribe(string &channel, int user_id) {
		channels[channel].insert(user_id);
	}

	/**
	* @param channel:
	* @param user_id:
	* @return: nothing
	*/
	void unsubscribe(string &channel, int user_id) {
		channels[channel].erase(user_id);
	}

	/**
	* @param channel:
	* @param message:
	* @return: nothing
	*/
	void publish(string &channel, string &message) {
	    for (int user_id : channels[channel]) {
	        PushNotification::notify(user_id, message);
	    }
	}
private:
    unordered_map<string, unordered_set<int>> channels;
};
