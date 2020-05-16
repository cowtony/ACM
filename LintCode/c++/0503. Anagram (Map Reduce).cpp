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
 */
class AnagramMapper: public Mapper {
public:
    void Map(Input<string>* input) {
        while (!input->done()) {
            for (string word : split(input->value(), " ")) {
                string anagram = word;
                sort(anagram.begin(), anagram.end());
                output(anagram, word);
            }
            input->next();
        }
    }
};


class AnagramReducer: public Reducer {
public:
    void Reduce(string &key, Input<string>* input) {
        vector<string> ret;
        while (!input->done()) {
            ret.push_back(input->value());
            input->next();
        }
        output(key, ret);
    }
};
