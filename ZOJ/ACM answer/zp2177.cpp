//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  int n,i,j,next[1000010],cs=0;
  char st[1000010];
  while (scanf("%d",&n) && n)
  {
    scanf("%s",st);
    i=1;
    next[1]=0;
    j=0;
    while (i<=n)
      if (j==0 || st[i-1]==st[j-1])
      {
        i++;
        j++;
        next[i]=j;
      }
      else
        j=next[j];
/*
    for (i=1;i<=n;i++)
      printf("%d ",next[i]);
    printf("\n");
*/
    printf("Test case #%d\n",++cs);

    for (i=1;i<=n/2;i++)
    {
      for (j=2;i*j<=n;j++)
        if (next[i*j+1]==i*(j-1)+1)
          printf("%d %d\n",i*j,j);
        else
          break;
      if (j*i<=n)
        i*=j-1;
      else
        break;
    }
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
