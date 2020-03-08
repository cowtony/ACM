//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//#include <iostream>
#include <stdio.h>
#include <string.h>
//using namespace std;
char ch[1000010];
int p[1000010];
int main(int argc, char* argv[])
{

  int i,n,j,k,s,cs;
  scanf("%d",&n);
  cs=0;
  while (n)
  {
    memset(p,0,sizeof(int)*(n+2));
    scanf("%s",ch);

    s=0;
    for (i=1;i<=n/2;i++)
      if (p[i]==0)
      {
        for (j=2;j<=n/i;j++)
        {
          for (k=1;k<=i;k++)
            if (ch[k-1]!=ch[j*i-i+k-1])
              break;
          if (i+1==k)
          {
            p[i*j]=j;
            if ((i*j)>s)
              s=i*j;
          }
          else
          {
            break;
          }
        }
        i*=j-1;
//        i--;
      }
    printf("Test case #%d\n",++cs);
    for (i=2;i<=s;i++)
      if (p[i])
        printf("%d %d\n",i,p[i]);
    printf("\n");
    scanf("%d",&n);
  }
  return 0;
}
//---------------------------------------------------------------------------
