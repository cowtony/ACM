class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if (customers.find(id) == customers.end()) {
            customers[id] = make_pair(stationName, t);
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        if (customers.find(id) == customers.end()) {
            return;
        }
        auto p = customers[id];
        customers.erase(id);
        string station_in = p.first;
        if (station_in > stationName) {
            swap(station_in, stationName);
        }
        stations[station_in + "-" + stationName].first += t - p.second;
        stations[station_in + "-" + stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        if (startStation > endStation) {
            swap(startStation, endStation);
        }
        auto& v = stations[startStation + "-" + endStation];

        return double(v.first) / v.second;
    }
private:
    unordered_map<string, pair<int, int>> stations; // Key: InStation-OutStation, value: <sum, count>
    unordered_map<int, pair<string, int>> customers;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
