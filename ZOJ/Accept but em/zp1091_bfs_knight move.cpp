//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//#define cin fin
//#include <fstream>
#include <iostream>
using namespace std;

int const w=8;
  int x[100],y[100],p[10][10];
int oka(int x,int y)
{
  if (x>0 && x<=w && y>0 && y<=w)
    return 1;
  else
    return 0;
}
int main(int argc, char* argv[])
{
  //ifstream fin("inpk1915.txt");
  int N,I,i,j,x0,y0,x1,y1,dp,h,t,f,hr,tr;
  char s0[5],s1[5];
  while (cin>>s0>>s1)
  {
    x0=s0[0]-'a'+1;
    y0=s0[1]-'0';
    x1=s1[0]-'a'+1;
    y1=s1[1]-'0';
    cout<<"To get from "<<s0<<" to "<<s1<<" takes ";
    if (x0==x1 && y0==y1)
      cout<<0;
    else
    {
    dp=0; h=0;t=1;f=1;
    for (i=0;i<10;i++)
      for (j=0;j<10;j++)
        p[i][j]=1;
    p[x0][y0]=0;
    x[0]=x0;
    y[0]=y0;

    while (f)
    {
      dp++;
      hr=t; tr=hr-1;
      for (i=h;i<t;i++)
      {
        if (oka(x[i]+2,y[i]+1) && p[x[i]+2][y[i]+1])                   //1
          if (x[i]+2==x1 && y[i]+1==y1)
          { f=0; break; }
          else
          { tr++; x[tr]=x[i]+2;y[tr]=y[i]+1; p[x[i]+2][y[i]+1]=0;}
        if (oka(x[i]+2,y[i]-1) && p[x[i]+2][y[i]-1])                   //2
          if (x[i]+2==x1 && y[i]-1==y1)
          { f=0; break; }
          else
          { tr++; x[tr]=x[i]+2;y[tr]=y[i]-1; p[x[i]+2][y[i]-1]=0;}
        if (oka(x[i]-2,y[i]-1) && p[x[i]-2][y[i]-1])                   //3
          if (x[i]-2==x1 && y[i]-1==y1)
          { f=0; break; }
          else
          { tr++; x[tr]=x[i]-2;y[tr]=y[i]-1; p[x[i]-2][y[i]-1]=0;}
        if (oka(x[i]-2,y[i]+1) && p[x[i]-2][y[i]+1])                   //4
          if (x[i]-2==x1 && y[i]+1==y1)
          { f=0; break; }
          else
          { tr++; x[tr]=x[i]-2;y[tr]=y[i]+1; p[x[i]-2][y[i]+1]=0;}
        if (oka(x[i]+1,y[i]+2) && p[x[i]+1][y[i]+2])                   //5
          if (x[i]+1==x1 && y[i]+2==y1)
          { f=0; break; }
          else
          { tr++; x[tr]=x[i]+1;y[tr]=y[i]+2; p[x[i]+1][y[i]+2]=0;}
        if (oka(x[i]+1,y[i]-2) && p[x[i]+1][y[i]-2])                   //6
          if (x[i]+1==x1 && y[i]-2==y1)
          { f=0; break; }
          else
          { tr++; x[tr]=x[i]+1;y[tr]=y[i]-2; p[x[i]+1][y[i]-2]=0;}
        if (oka(x[i]-1,y[i]-2) && p[x[i]-1][y[i]-2])                   //7
          if (x[i]-1==x1 && y[i]-2==y1)
          { f=0; break; }
          else
          { tr++; x[tr]=x[i]-1;y[tr]=y[i]-2; p[x[i]-1][y[i]-2]=0;}
        if (oka(x[i]-1,y[i]+2) && p[x[i]-1][y[i]+2])                   //8
          if (x[i]-1==x1 && y[i]+2==y1)
          { f=0; break; }
          else
          { tr++; x[tr]=x[i]-1;y[tr]=y[i]+2; p[x[i]-1][y[i]+2]=0;}
      }
      h=hr; t=tr+1;
    }
    cout<<dp;
    }
    cout<<" knight moves."<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
