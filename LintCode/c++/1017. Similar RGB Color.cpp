class Solution {
public:
    /**
     * @param color: the given color
     * @return: a 7 character color that is most similar to the given color
     */
    string similarRGB(string &color) {
        int r = parse(color.substr(1, 2));
        int g = parse(color.substr(3, 2));
        int b = parse(color.substr(5, 2));
        
        int max_sim = INT_MIN;
        stringstream ret;
        for (int rr : {r / 17, r / 17 + 1}) {
            for (int gg : {g / 17, g / 17 + 1}) {
                for (int bb : {b / 17, b / 17 + 1}) {
                    int sim = similarity(r, g, b, rr * 17, gg * 17, bb * 17);
                    if (max_sim < sim) {
                        max_sim = sim;
                        ret.str(std::string());
                        ret << "#" << std::hex << rr << rr << gg << gg << bb << bb;
                    }
                }
            }
        }
        return ret.str();
    }
    
    int parse(const string& color) {
        int ret = 0;
        for (char c : color) {
            ret = ret * 16;
            if (c >= '0' and c <= '9') {
                ret += c - '0';
            } else if (c >= 'a' and c <= 'z') {
                ret += c - 'a' + 10;
            } else {
                ret += c - 'A' + 10;
            }
        }
        return ret;
    }
    
    int similarity(int r, int g, int b, int r2, int g2, int b2) {
        r -= r2;
        g -= g2;
        b -= b2;
        return - r * r - g * g - b * b;
    }
};
