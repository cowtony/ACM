class Solution {
public:
    /**
     * @param words: an array of string
     * @param maxWidth: a integer
     * @return: format the text such that each line has exactly maxWidth characters and is fully
     */
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> word_queue;
        vector<string> ret;
        int len = 0;
        int space = maxWidth;
        for (string word : words) {
            if (len + word.length() + word_queue.size() > maxWidth) {
                string row;
                for (int i = 0; i < word_queue.size(); i++) {
                    int sp;
                    if (word_queue.size() - 1 - i > 0) {
                        sp = space / (word_queue.size() - 1 - i);
                        if (space % (word_queue.size() - 1 - i) > 0) {
                            sp++;
                        }
                    } else {
                        sp = space;
                    }
                    space -= sp;
                    
                    row += word_queue[i] + string(sp, ' ');
                }
                ret.push_back(row);
                len = 0;
                space = maxWidth;
                word_queue.clear();
            }
            
            word_queue.push_back(word);
            len += word.length();
            space -= word.length();  // Total space counter.
        }
        
        if (!word_queue.empty()) {
            string row;
            for (string word : word_queue) {
                if (!row.empty()) {
                    row += ' ';
                }
                row += word;
            }
            while (row.length() < maxWidth) {
                row += ' ';
            }
            ret.push_back(row);
        }
        
        return ret;
    }
};
