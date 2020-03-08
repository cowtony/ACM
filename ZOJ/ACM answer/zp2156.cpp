#include <stdio.h>

int c[4];
void cal(int pay)
{
  int sm=0,h=0,r,i,j,k,l,t[4];

  for (i=0;i<=c[3] && i*25<=pay;i++)
  {
    sm=i*25;
    if (sm+c[0]+c[1]*5+c[2]*10<pay)
      continue;
    for (j=0;j<=c[2] && i*25+j*10<=pay;j++)
    {
      sm=i*25+j*10;
      if (sm+c[0]+c[1]*5<pay)
        continue;
      for (k=0;k<=c[1] &&
           i*25+j*10+k*5<=pay;k++)
      {
        sm=i*25+j*10+k*5;
        if (sm+c[0]<pay)
          continue;
        for (l=0;l<=c[0] &&
             i*25+j*10+k*5+l<=pay;l++)
        {
          sm=i*25+j*10+k*5+l;

          if (sm==pay)
          {
            h++;
            if (h==1)
            {
              r=i+j+k+l;
              t[3]=i;
              t[2]=j;
              t[1]=k;
              t[0]=l;
            }
            else
            {
              if (i+j+k+l>r)
                printf("Throw in %d cents, %d nickels, \
%d dimes, and %d quarters.\n",
                        l,k,j,i);
              else
                printf("Throw in %d cents, %d nickels, \
%d dimes, and %d quarters.\n",
                        t[0],t[1],t[2],t[3]);
              return;
            }
            j=c[2];
            k=c[1];
            l=c[0];
          }
        }
      }
    }
  }
  if (h)
     printf("Throw in %d cents, %d nickels, \
%d dimes, and %d quarters.\n",
       t[0],t[1],t[2],t[3]);
  else
    puts("Charlie cannot \
buy coffee.");
  return;
}
int main(int argc, char* argv[])
{
  int i,n;
  while (scanf("%d%d%d%d%d",&n,c,c+1,c+2,c+3)
    && n+c[0]+c[1]+c[2]+c[3])
      cal(n);
  return 0;
}
//---------------------------------------------------------------------------
