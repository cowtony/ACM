class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& wordList) {
        unordered_set<string> dict{wordList.begin(), wordList.end()};
        dict.insert(start);
        if (dict.find(end) == dict.end()) {
            return {};
        }
        dict.insert(end);
        
        // Dijkstra algorithm. (BFS)
        unordered_map<string, int> distance;
        unordered_map<string, unordered_set<string>> predecessor;
        distance[end] = 0;
        
        queue<string> q;
        q.push(end);
        dict.erase(end);
        int depth = -1;
        while (!q.empty() and q.front() != start) {
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
                        predecessor[next] = {current};
                        q.push(next);
                    } else if (distance[next] == distance[current] + 1) {
                        predecessor[next].insert(current);
                    }
                }
            }
        }
        
        dfs(predecessor, {start}, end);
        return ret;
    }
    
private:
    vector<vector<string>> ret;
    void dfs(unordered_map<string, unordered_set<string>>& predecessor, vector<string> words, string& end) {
        if (words.back() == end) {
            ret.push_back(words);
            return;
        }
        for (string word : predecessor[words.back()]) {
            vector<string> temp = words;
            temp.push_back(word);
            dfs(predecessor, temp, end);
        }
    }
};
