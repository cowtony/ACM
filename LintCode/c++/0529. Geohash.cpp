class GeoHash {
public:
    /*
     * @param latitude: one of a location coordinate pair 
     * @param longitude: one of a location coordinate pair 
     * @param precision: an integer between 1 to 12
     * @return: a base32 string
     */
    string encode(double latitude, double longitude, int precision) {
        double lat_lo = -90, lat_hi = 90, lon_lo = -180, lon_hi = 180;
        int number = 0;
        int count = 0;
        string result;
        while (result.length() < precision) {
            double lon_mid = (lon_lo + lon_hi) / 2;
            if (longitude > lon_mid) {
                lon_lo = lon_mid;
            } else {
                lon_hi = lon_mid;
            }
            number = (number << 1) + (longitude > lon_mid);
            addChar(number, ++count, result);

            if (count == 5) {
                count = 0;
                result += m[number];
                number = 0;
            }
                        
            double lat_mid = (lat_lo + lat_hi) / 2;
            if (latitude > lat_mid) {
                lat_lo = lat_mid;
            } else {
                lat_hi = lat_mid;
            }
            number = (number << 1) + (latitude > lat_mid);
            addChar(number, ++count, result);
        }

        return result;
    }
    
    string m = "0123456789bcdefghjkmnpqrstuvwxyz";
    
    void addChar(int& number, int& count, string& result) {
        if (count == 5) {
            count = 0;
            result += m[number];
            number = 0;
        }
    }
};
