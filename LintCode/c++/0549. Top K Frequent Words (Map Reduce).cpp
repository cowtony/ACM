/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 * Definition of Document:
 * class Document {
 * public:
 *     int id; // document id
 *     string content; // document content
 * }
 */
class TopKFrequentWordsMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        while (!input->done()) {
            for (string word : split(input->value().content, " ")) {
                if (!word.empty()) {
                    output(word, 1);
                }
            }
            input->next();
        }
    }
};


class TopKFrequentWordsReducer: public Reducer {
public:
    void setUp(int k) {
        top_k = k;
    }

    void Reduce(string &key, Input<int>* input) {
        while (!input->done()) {
            count[key] += input->value();
            input->next();
        }
        
    }

    void cleanUp() {
        struct Node {
            int count = 0;
            string word;
            bool operator < (Node n) const {
                if (count == n.count) {
                    return word < n.word;
                } else {
                    return count > n.count;
                }
            }
        };
        priority_queue<Node> pq;
        for (auto p : count) {
            pq.push({p.second, p.first});
            if (pq.size() > top_k) {
                pq.pop();
            }
        }

        stack<Node> s;
        while (!pq.empty()) {
            s.push(pq.top());
            pq.pop();
        }
        while (!s.empty()) {
            string word = s.top().word;
            output(word, s.top().count);
            s.pop();
        }
    }
    
private:
    int top_k;
    unordered_map<string, int> count;
};
