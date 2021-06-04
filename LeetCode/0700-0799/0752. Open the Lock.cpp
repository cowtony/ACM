class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const string kDelimitor = "";
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> seen;
        queue<string> bfs;
        bfs.push("0000");
        bfs.push(kDelimitor);
        
        int step = 0;
        while (bfs.size() > 1) {
            if (dead.find(bfs.front()) != dead.end() || seen.find(bfs.front()) != seen.end()) {
                bfs.pop();
                continue;
            } else if (bfs.front() == kDelimitor) {
                step++;
                bfs.pop();
                bfs.push(kDelimitor);
                continue;
            } else if (bfs.front() == target) {
                return step;
            } 
    
            for (int i = 0; i < 4; i++) {
                for (int roll : {1, 9}) {
                    string combinition = bfs.front();
                    combinition[i] = (combinition[i] - '0' + roll) % 10 + '0';
                    if (combinition == target) {
                        return step + 1;  // Early return
                    }
                    bfs.push(combinition);
                }
            }
            seen.insert(bfs.front());
            bfs.pop();
        }
        
        return -1;
    }
};
