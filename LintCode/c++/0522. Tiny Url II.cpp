class TinyUrl2 {
public:
    /*
     * @param long_url: a long url
     * @param key: a short key
     * @return: a short url starts with http://tiny.url/
     */
    string createCustom(string &long_url, string &key) {
        if (short_to_long.find(key) != short_to_long.end()) {
            if (short_to_long.at(key) == long_url) {
                return "http://tiny.url/" + key;
            } else {
                return "error";
            }
        }
        if (long_to_short.find(long_url) != long_to_short.end()) {
            if (long_to_short.at(long_url) == key) {
                return "http://tiny.url/" + key;
            } else {
                return "error";
            }
        }
        short_to_long[key] = long_url;
        long_to_short[long_url] = key;
        
        return "http://tiny.url/" + key;
    }

    /*
     * @param long_url: a long url
     * @return: a short url starts with http://tiny.url/
     */
    string longToShort(string &long_url) {
        if (long_to_short.find(long_url) != long_to_short.end()) {
            return "http://tiny.url/" + long_to_short.at(long_url);
        }
        long_to_short[long_url] = to_string(current);
        short_to_long[to_string(current)] = long_url;
        return toUrl(current++);
    }

    /*
     * @param short_url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    string shortToLong(string &short_url) {
        return short_to_long.at(short_url.substr(16));
    }
    
private:
    int current = 100000;
    map<string, string> long_to_short;
    map<string, string> short_to_long;
    
    string toUrl(int id) {
        return "http://tiny.url/" + to_string(id);
    }
};
