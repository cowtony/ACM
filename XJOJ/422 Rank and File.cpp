/*
输入目前国际象棋的棋局，以及需要判定的是哪一方
输出该方现在是被将军还是被将死还是安全的

写个类，巨复杂
思路就是写个判断目前是否被将军的函数
然后遍历该方可走的每一步，对于走完那一步的情况，如果都是将军，则为被将死

关键词：模拟，巨复杂无比 
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct Position
{
    int column,row;
    Position(int i=0,int j=0):row(i),column(j){}
};

struct Chess
{
    char present;
    char map[8][8];
    
    friend istream& operator >>(istream& input,Chess& c)
    {
        input>>c.present;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                input>>c.map[i][j];
        return input;
    }
    
    vector<Position> itera_rook(int row,int cloumn);
    vector<Position> itera_bishop(int row,int cloumn);
    vector<Position> itera_queen(int row,int column);
    vector<Position> itera_knight(int row,int column);
    vector<Position> itera_king(int row,int column);
    bool check();
    bool checkmate();
};

int main()
{
    //freopen("aaa.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        Chess chess;
        cin>>chess;
        
        if(chess.present=='w')cout<<"WHITE IS ";
        else cout<<"BLACK IS ";
        
        if(chess.checkmate()==true)cout<<"CHECKMATED"<<endl;
        else if(chess.check()==true)cout<<"CHECKED"<<endl;
        else cout<<"SAFE"<<endl;
    }
    //while(1);
}

bool opponent(char self,char c)
{
    if(self>='a' && self<='z')return c>='A' && c<='Z';
    else if(self>='A' && self<='Z')return c>='a' && c<='z';
}

bool own(char self,char c)
{
    if(self>='A' && self<='Z')return c>='A' && c<='Z';
    else if(self>='a' && self<='z')return c>='a' && c<='z';
}

vector<Position> Chess::itera_rook(int row,int column)
{
    vector<Position> temp;
    for(int i=row+1;i<8;i++)
    {
        if(own(map[row][column],map[i][column])==true)break;
        temp.push_back(Position(i,column));
        if(opponent(map[row][column],map[i][column])==true)break;
    }
    for(int i=row-1;i>=0;i--)
    {
        if(own(map[row][column],map[i][column])==true)break;
        temp.push_back(Position(i,column));
        if(opponent(map[row][column],map[i][column])==true)break;
    }
    for(int j=column+1;j<8;j++)
    {
        if(own(map[row][column],map[row][j])==true)break;
        temp.push_back(Position(row,j));
        if(opponent(map[row][column],map[row][j])==true)break;
    }
    for(int j=column-1;j>=0;j--)
    {
        if(own(map[row][column],map[row][j])==true)break;
        temp.push_back(Position(row,j));
        if(opponent(map[row][column],map[row][j])==true)break;
    }
    return temp;
}

vector<Position> Chess::itera_bishop(int row,int column)
{
    vector<Position> temp;
    for(int i=row+1,j=column+1;i<8 && j<8;i++,j++)
    {
        if(own(map[row][column],map[i][j])==true)break;
        temp.push_back(Position(i,j));
        if(opponent(map[row][column],map[i][j])==true)break;
    }
    for(int i=row+1,j=column-1;i<8 && j>=0;i++,j--)
    {
        if(own(map[row][column],map[i][j])==true)break;
        temp.push_back(Position(i,j));
        if(opponent(map[row][column],map[i][j])==true)break;
    }
    for(int i=row-1,j=column+1;i>=0 && j<8;i--,j++)
    {
        if(own(map[row][column],map[i][j])==true)break;
        temp.push_back(Position(i,j));
        if(opponent(map[row][column],map[i][j])==true)break;
    }
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--)
    {
        if(own(map[row][column],map[i][j])==true)break;
        temp.push_back(Position(i,j));
        if(opponent(map[row][column],map[i][j])==true)break;
    }
    return temp;
}

vector<Position> Chess::itera_queen(int row,int column)
{
    vector<Position> a,b;
    a=itera_rook(row,column);
    b=itera_bishop(row,column);
    
    for(int i=0;i<b.size();i++)
        a.push_back(b[i]);
    
    return a;
}

vector<Position> Chess::itera_knight(int row,int column)
{
    vector<Position> temp;
    for(int i=row-2;i<=row+2;i++)
        for(int j=column-2;j<=column+2;j++)
            if(i>=0 && i<8 && j>=0 && j<8)
                if(abs(i-row)+abs(j-column)==3)
                    if(own(map[row][column],map[i][j])==false)
                        temp.push_back(Position(i,j));
    return temp;
}

vector<Position> Chess::itera_king(int row,int column)
{
    vector<Position> temp;
    for(int i=row-1;i<=row+1;i++)
        for(int j=column-1;j<=column+1;j++)
            if(i>=0 && i<8 && j>=0 && j<8)
                if(own(map[row][column],map[i][j])==false)
                    temp.push_back(Position(i,j));
    return temp;
}

bool Chess::check()
{
    string man;
    if(present=='w')man="RBQNKk";
    else man="rbqnkK";
    
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            vector<Position> temp;
            
                 if(map[i][j]==man[0])temp=itera_rook(i,j);
            else if(map[i][j]==man[1])temp=itera_bishop(i,j);
            else if(map[i][j]==man[2])temp=itera_queen(i,j);
            else if(map[i][j]==man[3])temp=itera_knight(i,j);
            else if(map[i][j]==man[4])temp=itera_king(i,j);

            for(int i=0;i<temp.size();i++)
                if(map[temp[i].row][temp[i].column]==man[5])return true;
        }
    return false;
}

bool Chess::checkmate()
{
    string man;
    if(present=='w')man="rbqnk";
    else man="RBQNK";
        
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            vector<Position> temp;
            int k;
                
                 if(map[i][j]==man[0]){temp=itera_rook(i,j);k=0;}
            else if(map[i][j]==man[1]){temp=itera_bishop(i,j);k=1;}
            else if(map[i][j]==man[2]){temp=itera_queen(i,j);k=2;}
            else if(map[i][j]==man[3]){temp=itera_knight(i,j);k=3;}
            else if(map[i][j]==man[4]){temp=itera_king(i,j);k=4;}

            for(int it=0;it<temp.size();it++)
            {
                Chess what=*this;
                what.map[i][j]='.';
                what.map[temp[it].row][temp[it].column]=man[k];
                if(what.check()==false)return false;
            }
        }
    return true;
}
