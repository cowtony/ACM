/**
 * Definition of Trip:
 * class Trip {
 * public:
 *     int id; // trip's id, primary key
 *     int driver_id, rider_id; // foreign key
 *     double lat, lng; // pick up location
 *     Trip(int rider, double lat, double lng);
 * }
 * Definition of Helper
 * class Helper {
 * public:
 *     static double get_distance(double lat1, double lng1,
 *                         double lat2, double lng2) {
 *         // return distance between (lat1, lng1) and (lat2, lng2)
 *     }
 * };
 */
class MiniUber {
public:
    MiniUber() {
        // initialize your data structure here.
    }

    // @param driver_id an integer
    // @param lat, lng driver's location
    // return matched trip information if there have matched rider or NULL
    Trip* report(int driver_id, double lat, double lng) {
        drivers[driver_id] = make_pair(lat, lng);
        if (trips.find(driver_id) == trips.end()) {
            return nullptr;
        } else {
            return trips[driver_id];
        }
    }

    // @param rider_id an integer
    // @param lat, lng rider's location
    // return a trip
    Trip* request(int rider_id, double lat, double lng) {
        double min_dist = 1.0e300;
        int driver = -1;
        for (auto p : drivers) {
            if (trips.find(p.first) != trips.end()) {
                continue;
            }
            double dist = Helper::get_distance(p.second.first, p.second.second, lat, lng);
            if (dist < min_dist) {
                min_dist = dist;
                driver = p.first;
            }
        }
        if (driver > 0) {
            Trip* trip = new Trip(rider_id, lat, lng);
            trip->driver_id = driver;
            trips[driver] = trip;
            return trip;
        } else {
            return nullptr;
        }
    }

private:
    map<int, pair<double, double>> drivers;
    map<int, Trip*> trips;
};
