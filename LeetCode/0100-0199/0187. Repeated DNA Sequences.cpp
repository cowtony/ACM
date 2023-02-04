class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> count;
        for (int i = 0; i <= int(s.length()) - 10; i++) {
            int hash_result = hash(s.substr(i, 10));
            count[hash_result]++;
        }

        vector<string> result;
        for (const auto& [key, value] : count) {
            if (value > 1) {
                result.push_back(unhash(key));
            }
        }
        return result;
    }

    int hash(string s) {
        static const unordered_map<char, int> kHash = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

        int result = 0;
        for (char c : s) {
            result <<= 2;
            result += kHash.at(c);
        }
        return result;
    }

    string unhash(int val) {
        static const unordered_map<int, char> kHash = {{0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}};

        string result;
        for (int i = 0; i < 10; i++) {
            result += kHash.at(val % 4);
            val >>= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};