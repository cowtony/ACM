#include <stdio.h>

const int mt=4;

struct typ
{
  int x,y;
} a[mt],b[mt];


int px[4]={-1,0,1,0},
    py[4]={0,-1,0,1};

int m,t,p[8][8];

void dfs(int d)
{
  int i,j,f;
    if (d<8)
      for (i=0;i<mt;i++)
      {
        for (j=0;j<4;j++)
          if ((j==0 && a[i].x>0)||(j==1 && a[i].y>0)
            ||(j==2 && a[i].x<7)||(j==3 && a[i].y<7))
          if (p[a[i].x+px[j]][a[i].y+py[j]]>0)
          { if ((j==0 && a[i].x>1)||(j==1 && a[i].y>1)
              ||(j==2 && a[i].x<6)||(j==3 && a[i].y<6))
            {
              p[a[i].x][a[i].y]=0;
              a[i].x+=px[j]*2;
              a[i].y+=py[j]*2;
              f=1;
              if (p[a[i].x][a[i].y]<0)
              {
                t--;
                m=d;
                if (t==0) return;
                f=0;
              }
              p[a[i].x][a[i].y]=1;
              dfs(d+1);
              if (t==0) return;
              if (f)
              {
                p[a[i].x][a[i].y]=0;
                a[i].x-=px[j]*2;
                a[i].y-=py[j]*2;
                p[a[i].x][a[i].y]=1;
              }
            }
          }
          else
          {
            p[a[i].x][a[i].y]=0;
            a[i].x+=px[j];
            a[i].y+=py[j];
            f=1;
            if (p[a[i].x][a[i].y]<0)
            {
              t--;
              m=d;
              if (t==0) return;
              f=0;
            }
            p[a[i].x][a[i].y]=1;
            dfs(d+1);
            if (t==0) return;
            if (f)
            {
              p[a[i].x][a[i].y]=0;
              a[i].x-=px[j];
              a[i].y-=py[j];
              p[a[i].x][a[i].y]=1;
            }
          }
      }
}

int main(int argc, char* argv[])
{
  int i,j;
  while (scanf("%d",&a[0].x)>0)
  {
    scanf("%d",&a[0].y);
    for (i=1;i<mt;i++)
      scanf("%d%d",&a[i].x,&a[i].y);
    for (i=0;i<mt;i++)
      scanf("%d%d",&b[i].x,&b[i].y);

    for (i=1;i<9;i++)
      for (j=1;j<9;j++)
        p[i][j]=0;

    for (i=0;i<mt;i++)
      p[a[i].x][a[i].y]=1;

    t=4;
    for (i=0;i<mt;i++)
      if (p[b[i].x][b[i].y]>0)
      {
        t--;
        p[b[i].x][b[i].y]=-1;
      }

    if (t)
      dfs(0);

    if (t==0)
      puts("YES");
    else
      puts("NO");

    printf("%d\n",m);
  }
  return 0;
}
//---------------------------------------------------------------------------
