#include <iostream>
using namespace std;

class Chessman;

class Board {
public:
    Board() {
        // Initilize, put all the Chessman to the original place.
    }
    
    Chessman getChessman(int x, int y) {
        // boundary check.
        return chess_board[x][y];
    }
    
    makeMove() {
        whos_turn != whos_turn;
    }
    
    checkWinner() {
    
    }


private:
    bool whos_turn;
    vector<vector<Chessman>> chess_board(8, vector<Chessman>(8, Chessman()));
};


class Chessman {
public:
    Chessman() {
        color = 0;
    }
    virtual bool validMove(const Board& board, int to_x, int to_y) {
        if (board.getChessman(to_x, to_y).color == this->color) {
            return false;
        }
        if (to_x < 0 || to_x >= 8 || to_y < 0 || to_y >= 8) {
            return false;
        }
        if (to_x == x && to_y == y) {
            return false;
        }
        return true;
    }
    
    virtual void makeMove() = 0;
    
private:
    int x = 0, y = 0;
    int color; // 1 as white, -1 as black, 0 as no chessman
};

class Solder : public Chessman {
    bool validMove(const Board& board, int to_x, int to_y) override {
        if (!Chessman::validMove(board, to_x, to_y)) {
            return false;
        }
        if (x == 1 && color == true || x == 6 && color == false) {
            // Starting point, you can move two position.
        }
    }
};

class King : public Chessman {
    bool validMove(const Board& board, int to_x, int to_y) override {
        if (!Chessman::validMove(board, to_x, to_y)) {
            return false;
        }
        if (abs(to_x - x) == 1 || abs(to_y - y) == 1) {
            return true;
        }
        return false;
    }
};

class Queen : public Chessman {

};


bool validation(int chessman, x, y, x2, y2) {
    switch (chessman) {
    case 1: // Queen
        
    case 2: // King
        //
    }

}

int main() {
    
    Board board;
    
    King king;
    
    king.validMove(b, 1, 1);
    
    while ()


    return 0;
}
