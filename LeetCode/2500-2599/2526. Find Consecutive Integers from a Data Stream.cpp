class DataStream {
public:
    DataStream(int value, int k) : kValue(value), K(k) {
        
    }
    
    bool consec(int num) {
        if (num == kValue) {
            count++;
        } else {
            count = 0;
        }
        return count >= K;
    }

  private:
    const int K;
    const int kValue;
    int count = 0;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
