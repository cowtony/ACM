class Robot {
public:
    Robot(int width, int height) : kWidth(width), kHeight(height) {
        kPerimeter = (kWidth + kHeight - 2) * 2;
    }
    
    void step(int num) {
        if (num == 0) {
            return;
        }
        num = (num - 1 + kPerimeter) % kPerimeter + 1;  // At least do one round for direction correctness.

        int steps;
        switch (direction) {
            case 0:
                steps = kWidth - 1 - x;
                x += min(steps, num);
                break;
            case 1:
                steps = kHeight - 1 - y;
                y += min(steps, num);
                break;
            case 2:
                steps = x;
                x -= min(steps, num);
                break;
            case 3:
                steps = y;
                y -= min(steps, num);
                break;
        }
        if (num > steps) {
            direction = (direction + 1) % 4;
            step(num - steps);
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return kDir.at(direction);
    }
private:
    int direction = 0;  // Facing east
    const vector<string> kDir = {"East", "North", "West", "South"};
    const int kWidth, kHeight;
    int kPerimeter;
    int x = 0, y = 0;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
