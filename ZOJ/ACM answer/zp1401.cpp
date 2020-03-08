//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>


int dy[4][5]={{0},
              {0,1,2,3,4},
              {0,1,1,1,2},
              {0,0,1,2,2}};

int dx[5][4]={{0,0,0,0},
              {0,1,0,1},
              {0,2,0,2},
              {0,2,1,2},
              {0,3,1,3}};

int summ(int n,int x1,int x2,int y2,int y1)
{
  if (n<=2)
    if (y1==y2)
      return dy[x2][y2]-dy[x1][y1];
    else
      return dx[x2][y2]-dx[x1][y1];
  else
  if (y1==y2)
  {
    if (y1==pw[n-1]-1)
      return (x1==0)+(x2==pw[n]);
    else
    if (y1==1) return x2-x1;
    else
    if (y1<pw[n-1]-1)
      if (x1>=pw[n-1])
        sm+=summ(n-1,x1-pw[n-1],x2-pw[n-1],y1,y1);
      else
      if (x2<=pw[n-1])
        sm+=summ(n-1,x1,x2,y1,y1);
      else
        sm+=summ(n-1,x1,pw[n-1],y1,y1)+summ(n-1,0,x2-pw[n-2],y1,y1);
    else
    if (y1>pw[n-1]-1)
      if (x1>=pw[n-1])
        sm+=summ(n-1,pw[n]-y1,pw[n]-y1,x2-pw[n-1],x1);
      else
      if (x2<=pw[n-1])
        sm+=summ(n-1,pw[n]-y1,pw[n]-y1,pw[n-1]-x1,pw[n-1]-x2);
      else
        sm+=summ(n-1,pw[n]-y1,pw[n]-y1,pw[n-1]-x1,0)+summ(n-1,pw[n]-y1,pw[n]-y1,x2-pw[n-1],0);
  }
  else
  if (x1==x2)
  {
    if (x1==pw[n-1]-1)
      return (y2>=pw[n-1] && y1<pw[n-1]);
    else
    if (x1<pw[n-1]-1)
      if (y1>=pw[n-1])
        sm+=summ(n-1,y1-pw[n-1],y2-pw[n-1],pw[n-1]-x1,pw[n-1]-x1);
      else
      if (y2<=pw[n-1])
        sm+=summ(n-1,x1,x1,y2,y1);
      else
        sm+=summ(n-1,0,y2-pw[n-1],pw[n-1]-x1,pw[n-1]-x1)+summ(n-1,x1,x2,pw[n-1],y1);
    else
    if (x1>pw[n-1]-1)
      if (y1>=pw[n-1])
        sm+=summ(n-1,y1-pw[n-1],y2-pw[n-1],x1-pw[n-1],x1-pw[n-1]);
      else
      if (y2<=pw[n-1])
        sm+=summ(n-1,x1-pw[n-1],x1-pw[n-1],y2,y1);
      else
        sm+=summ(n-1,0,y2-pw[n-1],x1-pw[n-1],x1-pw[n-1])+summ(n-1,x1-pw[n-1],x1-pw[n-1],y2,y1);
  }
  return 0;
}
int main(int argc, char* argv[])
{
  pw[0]=1;
  for (i=1;i<30;i++)
    pw[i]=pw[i-1]*2;

  return 0;
}
//---------------------------------------------------------------------------
 