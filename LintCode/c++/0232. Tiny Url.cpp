class TinyUrl {
public:
    /*
     * @param url: a long url
     * @return: a short url starts with http://tiny.url/
     */
    string longToShort(string &url) {
        if (long_to_short.find(url) != long_to_short.end()) {
            return suffix + long_to_short.at(url);
        }
        long_to_short[url] = to_string(inc_id);
        short_to_long[to_string(inc_id)] = url;
        return suffix + to_string(inc_id++);
    }

    /*
     * @param url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    string shortToLong(string &url) {
        return short_to_long.at(url.substr(suffix.length()));
    }

private:
    const string suffix = "http://tiny.url/";
    int inc_id = 100000;
    unordered_map<string, string> long_to_short;
    unordered_map<string, string> short_to_long;
};
