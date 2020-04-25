class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        unordered_set<string> dict{wordList.begin(), wordList.end()};
        dict.insert(start);
        if (dict.find(end) == dict.end()) {
            return 0;
        }
        
        // Dijkstra algorithm. (BFS)
        unordered_map<string, int> distance;
        distance[end] = 0;
        queue<string> q;
        q.push(end);
        dict.erase(end);
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            dict.erase(current);

            // Enumerate all one edit distance word.
            for (int i = 0; i < current.length(); i++) {
                string next = current;
                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;
                    if (next == current or dict.find(next) == dict.end()) {
                        continue;
                    }
                    
                    if (distance.find(next) == distance.end() or distance[next] > distance[current] + 1) {
                        distance[next] = distance[current] + 1;
                        q.push(next);
                    }
                    if (next == start) {
                        return distance[next] + 1;
                    }
                }
            }
        }
        
        return 0;
    }
};
