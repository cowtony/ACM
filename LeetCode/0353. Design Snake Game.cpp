class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        board = vector<vector<bool>>(height, vector<bool>(width, false));
        board[0][0] = true;
        snake.push_front({0, 0});
        for (auto f : food) {
            foods.push({f[0], f[1]});
        }
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        static const unordered_map<string, int> kX = {{"U", -1}, {"D", 1}, {"L", 0}, {"R", 0}};
        static const unordered_map<string, int> kY = {{"U", 0}, {"D", 0}, {"L", -1}, {"R", 1}};
        
        auto head = snake.front();
        head.first += kX.at(direction);
        head.second += kY.at(direction);
        
        if (head.first < 0 or head.first >= board.size() or head.second < 0 or head.second >= board[0].size()) {
            return -1;
        }
        
        if (head == foods.front()) {
            foods.pop();
        } else {
            auto tail = snake.back();
            snake.pop_back();
            board[tail.first][tail.second] = false;
        }
        
        if (board[head.first][head.second] == true) {
            return -1;
        }
        board[head.first][head.second] = true;
        snake.push_front(head);
        
        return snake.size() - 1;
    }

private:
    int width_, height_;
    deque<pair<int, int>> snake;
    queue<pair<int, int>> foods;
    vector<vector<bool>> board;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
