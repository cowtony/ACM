/**
 * Definition of Location:
 * class Location {
 * public:
 *     double latitude, longitude;
 *     static Location create(double lati, double longi) {
 *         // This will create a new location object
 *     }
 * };
 * Definition of Restaurant
 * class Restaurant {
 * public:
 *     int id;
 *     string name;
 *     Location location;
 *     static Restaurant create(string &name, Location &location) {
 *         // This will create a new restaurant object,
 *         // and auto fill id
 *     }
 * };
 * Definition of Helper
 * class Helper {
 * public:
 *     static get_distance(Location &location1, Location &location2) {
 *         // return distance between location1 and location2.
 *     }
 * };
 * class GeoHash {
 * public:
 *     static string encode(Location &location) {
 *         // return convert location to a GeoHash string
 *     }
 *     static Location decode(string &hashcode) {
 *          // return convert a GeoHash string to location
 *     }
 * };
 */
class MiniYelp {
public:
    MiniYelp() {
        // initialize your data structure here.
    }

    // @param name a string
    // @param location a Location
    // @return an integer, restaurant's id
    int addRestaurant(string name, Location &location) {
        restaurants[auto_inc_id] = Restaurant::create(name, location);
        return auto_inc_id++;
    }

    // @param restaurant_id an integer
    void removeRestaurant(int restaurant_id) {
        restaurants.erase(restaurant_id);
    }

    // @param location a Location
    // @param k an integer, distance smaller than k miles
    // @return a list of restaurant's name and sort by 
    // distance from near to far.
    vector<string> neighbors(Location &location, double k) {
        multimap<double, string> nearby;
        for (auto p : restaurants) {
            double dist = Helper::get_distance(p.second.location, location);
            if (dist < k) {
                nearby.insert(make_pair(dist, p.second.name));
            }
        }
        vector<string> ret;
        for (auto p : nearby) {
            ret.push_back(p.second);
        }
        return ret;
    }
private:
    int auto_inc_id = 1;
    unordered_map<int, Restaurant> restaurants;
};
