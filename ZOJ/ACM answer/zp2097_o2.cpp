#include<iostream> 
#include<string> 
#include<queue> 
#include<algorithm> 
using namespace std; 

int Chessboard[8][8][5]; 
int startX,startY,endX,endY; 
int step[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; 
struct point 
{ 
   point(){} 
   point(int i,int j,int k):x(i),y(j),state(k){} 
   int x,y,state; 
}; 

void Read() 
{ 
   startX--;startY--; 
   endX--;endY--; 
    
   int i,j; 
   for(i=0;i<8;i++){ 
      for(j=0;j<8;j++){ 
         memset(Chessboard[i][j],0,sizeof(int)*5); 
         cin >> Chessboard[i][j][0]; 
      } 
   } 
} 

void Solve() 
{ 
   if(startX == endX && startY == endY){ 
      cout << "0" << endl; 
      return ; 
   } 
   queue<point> Q; 
   point start(startX,startY,1),temp; 
   Q.push(start); 
   int i; 
   int x,y,state,cost; 
   while(!Q.empty()) 
   { 
      temp = Q.front(); 
      Q.pop(); 
      for(i=0;i<4;i++) 
      { 
         x = temp.x + step[i][0]; 
         y = temp.y + step[i][1]; 
         if((x >= 0 && x < 8) && (y >= 0 && y < 8)) 
         { 
            cost = temp.state * Chessboard[x][y][0]; 
            state = cost % 4 + 1; 
            if(Chessboard[x][y][state] == 0 || 
               Chessboard[x][y][state] > cost+Chessboard[temp.x][temp.y][temp.state]) 
            { 
               Chessboard[x][y][state] = cost + Chessboard[temp.x][temp.y][temp.state]; 
               if(x != endX || y != endY) 
                  Q.push(point(x,y,state)); 
            } 
         } 
      }//for 
   }//while 
    
   sort(&Chessboard[endX][endY][1],&Chessboard[endX][endY][4]); 
   i=1; 
   while(Chessboard[endX][endY][i] == 0) 
      i++; 
   cout << Chessboard[endX][endY][i] << endl; 
} 

int main() 
{ 
   while(cin >> startX >> startY >> endX >> endY) 
   { 
      if(startX == 0 && startY == 0 && endX == 0 && endY == 0) 
         break; 
      Read(); 
      Solve(); 
   } 
   return 0; 
} 
