template<class K = int, class V = int>
class LRUCache {
public:
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    V get(K key) {
        if (data.find(key) == data.end()) {
            return V();
        }
        auto it = data.at(key).first;
        frequent.push_front(*it);
        frequent.erase(it);
        data[key].first = frequent.begin();
        return data.at(key).second;
    }
    
    V getOldest() const {
        if (frequent.empty()) {
            return V();
        }
        return data.at(frequent.back()).second;
    }
    
    void put(K key, V value) {
        if (data.find(key) != data.end()) {
            get(key);
            data[key].second = value;
            return;
        }
        if (frequent.size() == max_size) {
            K key = frequent.back();
            data.erase(key);
            frequent.pop_back();
        }
        frequent.push_front(key);
        data[key] = make_pair(frequent.begin(), value);
    }
    
private:
    int max_size;
    unordered_map<K, pair<typename list<K>::iterator, V>> data; // <key, <iterator, value>>
    list<K> frequent; // Store keys as doublely linked list. newest->oldest
};

class Solution {
public:
    /* 
    // General solution.
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> count;
        int j = 0;
        int max_len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
            while (count.size() > k) {
                if (--count[s[j]] == 0) {
                    count.erase(s[j]);
                }
                j++;
            }
            max_len = max(max_len, i - j + 1);
        }
        
        return max_len;
    }
    */
    
    // Follow up: Streaming algorithm.
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        LRUCache<char, int> lru(k + 1);
        lru.put('#', -1);
        int i = 0;
        int max_len = 0;
        for (char c : s) {
            lru.put(c, i);
            max_len = max(max_len, i - lru.getOldest());
            i++;
        }
        return max_len;
    }
};
