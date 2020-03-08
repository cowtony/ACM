//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{

  int n,x,s,a,i,j,t,p[1000];
  while (scanf("%d",&n) && n)
  {
    while (scanf("%d",&x) &&x)
    {
      s=x-1;
      for (j=0;j<x;j++)
        p[j]=j;
      a=x+1;

      t=1;
      for (i=1;i<n;i++)
      {
        scanf("%d",&x);
        if (t)
        if (x>=a || x==p[s])
        {
          if (x==p[s])
            s--;
          else
            if (x>=a)
            {
              for (j=a;j<x;j++)
                p[j-a+s+1]=j;
              s+=x-a;
              a=x+1;
            }
        }
        else
          t=0;
      }
      if (t)
        printf("Yes\n");
      else
        printf("No\n");
    }
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
 