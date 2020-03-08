#include <stdio.h>

char dir[4]="NESW";
int dx[4]={-1,0,1,0},
    dy[4]={0,1,0,-1};

int main(int argc, char* argv[])
{
  int i,j,n,m,x,y,d,a[62][62];
  char ch,st[62];
  while (scanf("%d%d",&n,&m)>0)
  {
    gets(st);
    for (i=0;i<n;i++)
    {
      gets(st);
      for (j=0;j<m;j++)
        if (st[j]=='*')
          a[i+1][j+1]=1;
        else
          a[i+1][j+1]=0;
    }
    scanf("%d%d",&x,&y);
    d=0;
    while (scanf("%c",&ch) && ch!='Q')
    {
      if (ch=='R')
        d=(d+1)%4;
      else  if (ch=='L')
        d=(d+3)%4;
      else  if (ch=='F')
      {
        if (a[x+dx[d]][y+dy[d]]==0)
        {
          x+=dx[d];
          y+=dy[d];
        }
      }
    }
    printf("%d %d %c\n",x,y,dir[d]);
  }
  return 0;
}
//---------------------------------------------------------------------------
