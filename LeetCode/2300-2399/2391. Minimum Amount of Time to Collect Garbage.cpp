class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int result = 0;
        size_t last_m = 0, last_p = 0, last_g = 0;

        for (int i = 0; i < garbage.size(); i++) {
            result += garbage[i].length();
            for (char c : garbage[i]) {
                switch (c) {
                    case 'M': last_m = i; break;
                    case 'P': last_p = i; break;
                    case 'G': last_g = i; break;
                }
            }
        }

        for (int i = 1; i < travel.size(); i++) {
            travel[i] += travel[i - 1];
        }

        if (last_m > 0) {
            result += travel[last_m - 1];
        }
        if (last_p > 0) {
            result += travel[last_p - 1];
        }
        if (last_g > 0) {
            result += travel[last_g - 1];
        }
        return result;
    }
};