class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        pos = 0;
    }
    
    void visit(string url) {
        pos++;
        history.erase(history.begin() + pos, history.end());
        history.push_back(url);
    }
    
    string back(int steps) {
        pos = max(0, (pos - steps));
        return history[pos];
    }
    
    string forward(int steps) {
        pos = min(pos + steps, int(history.size()) - 1);
        return history[pos];
    }
    
private:
    int pos;
    vector<string> history;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
