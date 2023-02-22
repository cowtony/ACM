class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());

        int current = 0;
        int future = 0;
        int count = 0;
        for (int i = 0; i < clips.size(); i++) {
            if (clips[i][0] > future) {
                return -1;
            } else if (clips[i][0] > current) {
                current = future;
                count++;
            }
            future = max(future, clips[i][1]);
            if (future >= time) {
                return count + 1;
            }
        }
        return future < time? -1 : count;
    }
};
