class LoadBalancer {
public:
    LoadBalancer() {
        srand(time(NULL));
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        servers.emplace_back(server_id);
    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        for (auto it = servers.begin(); it != servers.end(); it++) {
            if (*it == server_id) {
                servers.erase(it);
                break;
            }
        }
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        return servers[rand() % servers.size()];
    }
private:
    vector<int> servers;
};
