template<class Iterator>
void inplaceMerge(const Iterator& begin, const Iterator& mid, const Iterator& end) {
    std::vector<typename Iterator::value_type> temp;
    temp.reserve(std::distance(begin, end));
    Iterator l = begin;
    Iterator r = mid;
    while (l != mid and r != end) {
        if (r->length() < l->length()) { temp.emplace_back(*r++); }
        else { temp.emplace_back(*l++); }
    }
    temp.insert(temp.end(), l, mid);
    temp.insert(temp.end(), r, end);
    std::move(temp.begin(), temp.end(), begin);
}

template<class Iterator>
void mergeSort(const Iterator& begin, const Iterator& end) {
    int size = std::distance(begin, end);   
    if (size <= 1) { return; }
    Iterator mid = std::next(begin, size / 2);
    mergeSort(begin, mid); // sort left half
    mergeSort(mid, end); // sort right half
    inplaceMerge(begin, mid, end); // merge left and right.
}

class Solution {
public:
    string arrangeWords(string text) {
        if (text.empty()) {
            return "";
        }
        text[0] = text[0] - 'A' + 'a';
        
        vector<string> words = split(text, " ");
        mergeSort(words.begin(), words.end());
        string res = join(words, " ");
        
        res[0] = res[0] - 'a' + 'A';
        return res;
    }
    
    vector<string> split(string s, string delimiter) {
        vector<string> res;
        size_t p = 0;
        while (true) {
            size_t pos = s.find(delimiter, p);
            if (pos != string::npos) {
                res.emplace_back(s.substr(p, pos - p));
                p = pos + delimiter.length();
            } else {
                res.emplace_back(s.substr(p));
                break;
            }
        }
        return res;
    }
    
    string join(vector<string> words, string s) {
        if (words.empty()) {
            return "";
        }
        string res = words[0];
        for (int i = 1; i < words.size(); i++) {
            res += s + words[i];
        }
        return res;
    }
};
