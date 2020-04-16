class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long_to_short.find(longUrl) != long_to_short.end()) {
            return suffix + long_to_short.at(longUrl);
        }
        long_to_short[longUrl] = to_string(inc_id);
        short_to_long[to_string(inc_id)] = longUrl;
        return suffix + to_string(inc_id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_to_long.at(shortUrl.substr(suffix.length()));
    }
    
private:
    const string suffix = "http://tinyurl.com/";
    int inc_id = 100000;
    unordered_map<string, string> long_to_short;
    unordered_map<string, string> short_to_long;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
