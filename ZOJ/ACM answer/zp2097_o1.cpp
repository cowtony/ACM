#include <iostream> 
#include <string> 
#include <deque> 
using namespace std; 


struct frame{int i,j,k;}; 
frame direction[4]={{-1,0},{0,1},{1,0},{0,-1}}; 

frame operator+(frame a,frame b) 
{ 
      frame c; 
      c.i=a.i+b.i; 
      c.j=a.j+b.j; 
      return c; 
} 

bool leg(frame a) 
{ 
      if(a.i>=0&&a.i<8&&a.j>=0&&a.j<8) 
            return 1; 
      return 0; 
} 

int main() 
{ 
      int x0,y0,xd,yd; 
      int data[8][8],dp[8][8][4]; 
      while( cin>>x0>>y0>>xd>>yd && (x0||y0||xd||yd)) 
      { 
            x0--;y0--;xd--;yd--; 
            memset(dp,-1,sizeof(dp)); 
            for(int i=0;i<8;i++) 
                  for(int j=0;j<8;j++) 
                        cin>>data[i][j]; 
            dp[x0][y0][0]=0; 
            frame t; 
            deque<frame> cc; 
            t.i=x0; t.j=y0; t.k=0; 
            cc.push_back(t); 
            while(!cc.empty()) 
            { 
                  t=cc.front(); 
                  cc.pop_front(); 
                  for(int i=0;i<4;i++) 
                  { 
                        frame now; 
                        now=t+direction[i]; 
                        if(!leg(now)) continue; 
                        int cost,allcost; 
                        cost=(t.k+1)*data[now.i][now.j]; 
                        now.k=cost%4; 
                        allcost=dp[t.i][t.j][t.k]+cost; 
                        if( dp[now.i][now.j][now.k]==-1 || allcost<dp[now.i][now.j][now.k]) 
                        { 
                              dp[now.i][now.j][now.k]=allcost; 
                              cc.push_back(now); 
                        } 
                  } 
            } 
            unsigned min=(unsigned)-1; 
            for(int i=0;i<4;i++) 
                  if(dp[xd][yd][i]!=-1&&dp[xd][yd][i]<min) 
                        min=dp[xd][yd][i]; 
            cout<<min<<endl; 
      } 
      return 0; 
}