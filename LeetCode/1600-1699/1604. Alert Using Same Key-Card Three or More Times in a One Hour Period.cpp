class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> name_times;
        for (int i = 0; i < keyName.size(); i++) {
            int minute = stoi(keyTime[i].substr(0, 2)) * 60 + stoi(keyTime[i].substr(3));
            name_times[keyName[i]].push_back(minute);
        }
        vector<string> result;
        for (auto& [name, times] : name_times) {
            sort(times.begin(), times.end());
            for (int i = 2; i < times.size(); i++) {
                if (times[i] - times[i - 2] <= 60) {
                    result.push_back(name);
                    break;
                }
            }
        }
        return result;
    }
};