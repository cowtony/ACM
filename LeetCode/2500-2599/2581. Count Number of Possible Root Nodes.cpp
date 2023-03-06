class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        unordered_map<int, vector<int>> tree;
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        unordered_map<int, unordered_set<int>> guesses_map;
        for (const auto& guess : guesses) {
            guesses_map[guess[0]].insert(guess[1]);
        }

        int correct_guess = DfsForRoot0(tree, guesses_map, -1, 0);
        return ReRooting(tree, guesses_map, k, -1, 0, correct_guess);
    }

private:
    int DfsForRoot0(const unordered_map<int, vector<int>>& tree,
                    const unordered_map<int, unordered_set<int>>& guesses, 
                    int prev, int node) {
        int correct_guess = 0;
        if (guesses.count(prev) > 0 && guesses.at(prev).count(node) > 0) {
            correct_guess++;
        }
        for (int next : tree.at(node)) {
            if (next == prev) {
                continue;
            }
            correct_guess += DfsForRoot0(tree, guesses, node, next);
        }
        return correct_guess;
    }

    int ReRooting(const unordered_map<int, vector<int>>& tree, 
                  const unordered_map<int, unordered_set<int>>& guesses, 
                  int k, int prev, int node, int correct_guess) {
        if (guesses.count(prev) > 0 && guesses.at(prev).count(node) > 0) {
            correct_guess--;
        }
        if (guesses.count(node) > 0 && guesses.at(node).count(prev) > 0) {
            correct_guess++;
        }
        int valid_count = 0;
        if (correct_guess >= k) {
            valid_count++;
        }

        for (int next : tree.at(node)) {
            if (next == prev) {
                continue;
            }
            valid_count += ReRooting(tree, guesses, k, node, next, correct_guess);
        }
        return valid_count;
    }
};
