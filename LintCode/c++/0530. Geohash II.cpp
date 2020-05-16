class GeoHash {
public:
    /*
     * @param geohash: geohash a base32 string
     * @return: latitude and longitude a location coordinate pair
     */
    vector<double> decode(string &geohash) {
        string code = "0123456789bcdefghjkmnpqrstuvwxyz";
        unordered_map<char, int> m;
        for (int i = 0; i < code.size(); ++i) {
            m[code.at(i)] = i;
        }
        
        vector<bool> sequence;
        for (int i = geohash.size() - 1; i >= 0; --i) {
            int num = m.at(geohash.at(i));
            for (int j = 0; j < 5; ++j) {
                sequence.push_back(num % 2 == 1);
                num >>= 1;
            }
        }
        
        double lat_lo = -90, lat_hi = 90, lon_lo = -180, lon_hi = 180;
        for (int i = sequence.size() - 1; i >= 0; --i) {
            if (sequence[i]) {
                lon_lo = (lon_lo + lon_hi) / 2;
            } else {
                lon_hi = (lon_lo + lon_hi) / 2;
            }
            
            if (--i < 0) {
                break;
            }
            
            if (sequence[i]) {
                lat_lo = (lat_lo + lat_hi) / 2;
            } else {
                lat_hi = (lat_lo + lat_hi) / 2;
            }
        }
        return {(lat_lo + lat_hi) / 2, (lon_lo + lon_hi) / 2};
    }
};
