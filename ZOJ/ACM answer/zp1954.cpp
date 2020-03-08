//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int rx[101010],ry[101010];

void sub1(int &x,int &y)
{
  y++;
}
void sub2(int &x,int &y)
{
  x--;
}
void sub3(int &x,int &y)
{
  y--;
}                         
void sub4(int &x,int &y)
{
  x++;
  y--;
}
void sub5(int &x,int &y)
{
  x++;
}

void sub6(int &x,int &y)
{
  x--;
  y++;
}

int main(int argc, char* argv[])
{
  int x,y,s,i,j;
  x=0;
  y=0;
  s=1;
  i=1;
  while (s<=100000)
  {
    for (j=0;j<i;j++)
    {
      sub1(x,y);
      s++;
      rx[s]=x;
      ry[s]=y;
    }
    for (j=0;j<i-1;j++)
    {
      sub6(x,y);
      s++;
      rx[s]=x;
      ry[s]=y;
    }
    for (j=0;j<i;j++)
    {
      sub2(x,y);
      s++;
      rx[s]=x;
      ry[s]=y;
    }
    for (j=0;j<i;j++)
    {
      sub3(x,y);
      s++;
      rx[s]=x;
      ry[s]=y;
    }
    for (j=0;j<i;j++)
    {
      sub4(x,y);
      s++;
      rx[s]=x;
      ry[s]=y;
    }
    for (j=0;j<i;j++)
    {
      sub5(x,y);
      s++;
      rx[s]=x;
      ry[s]=y;
    }
    i++;
  }

  while (scanf("%d",&i)!=EOF)
  {
    printf("%d %d\n",rx[i],ry[i]);
  }

  return 0;
}
//---------------------------------------------------------------------------
 