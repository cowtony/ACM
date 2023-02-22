class ATM {
  public:
    ATM() : notes(5, 0) {}
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) {
            notes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> result(kFace.size(), 0);
        for (int i = kFace.size() - 1; i >= 0; i--) {
            result[i] = min(int64_t(amount) / kFace[i], notes[i]);
            notes[i] -= result[i];
            amount -= result[i] * kFace[i];
        }
        if (amount > 0) {  // Rollback
            for (int i = 0; i < kFace.size(); i++) {
                notes[i] += result[i];
            }
            return {-1};
        }
        return result;
    }

  private:
    vector<int64_t> notes;
    const vector<int> kFace = {20, 50, 100, 200, 500};
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
