//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string.h>
#include <math.h>

double dist(double x,double y)
{
  return sqrt(x*x+y*y);
}
int main(int argc, char* argv[])
{
  double x,y,sqr2=sqrt(0.5);
  char st[210];
  int ln,i,k,cs=0;
  while (scanf("%s",st) && st[0]!='E')
  {
    ln=strlen(st);
    i=0;

    x=0; y=0;

    while (i<ln)
    {
      k=0;
      while (st[i]<='9' && st[i]>='0')
      {
        k*=10;
        k+=st[i]-'0';
        i++;
      }

      if (st[i+1]=='W' || st[i+1]=='E')
      {
        if (st[i]=='N' && st[i+1]=='E')
        { x+=k*sqr2; y+=k*sqr2; }
        else
        if (st[i]=='N' && st[i+1]=='W')
        { x-=k*sqr2; y+=k*sqr2; }
        else
        if (st[i]=='S' && st[i+1]=='E')
        { x+=k*sqr2; y-=k*sqr2; }
        else
        if (st[i]=='S' && st[i+1]=='W')
        { x-=k*sqr2; y-=k*sqr2; }
        i++;
      }
      else
      {
        if (st[i]=='N')
          y+=k;
        else
        if (st[i]=='S')
          y-=k;
        else
        if (st[i]=='E')
          x+=k;
        else
        if (st[i]=='W')
          x-=k;
      }
      i++;
    }

    printf("Map #%d\n",++cs);
    printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
    printf("The distance to the treasure is %.3lf.\n\n",dist(x,y));
  }
  return 0;
}
//---------------------------------------------------------------------------
