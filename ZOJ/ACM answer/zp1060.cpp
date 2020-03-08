//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
int main(int argc, char* argv[])
{
  int i,j,k,n,x,er,r,s,l,q,
      v[30][30],w[30][30],p[30][30];
  char st[30];
  while (scanf("%d%d",&n,&x) && (n || x))
  {
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        p[i][j]=0;

    er=-1;
    s=0;
    r=-1;
    for (i=0;i<x;i++)
    {
      scanf("%s",st);
      if (er==-1 && s==0)
      {
        if (p[st[2]-'A'][st[0]-'A']==1)
          er=i;
        else
//        if (s==0)
        {
          p[st[0]-'A'][st[2]-'A']=1;

          for (j=0;j<n;j++)
            if (p[j][st[0]-'A'])
            {
              p[j][st[2]-'A']=1;
              for (k=0;k<n;k++)
                if (p[st[2]-'A'][k])
                {
                  p[st[0]-'A'][k]=1;
                  p[j][k]=1;
                }
            }

          for (j=0;j<n;j++)
            if (p[st[2]-'A'][j])
            {
              p[st[0]-'A'][j]=1;
              for (k=0;k<n;k++)
                if (p[k][st[0]-'A'])
                {
                  p[k][st[2]-'A']=1;
                  p[k][j]=1;
                }
            }

          for (j=0;j<n;j++)
            for (k=0;k<n;k++)
              s+=p[j][k];
          if (s==n*(n-1)/2)
            r=i;
          else
            s=0;
        }
      }
    }
    if (er>=0)
      printf("Inconsistency found after %d relations.\n",er+1);
    else
      if (r==-1)
        printf("Sorted sequence cannot be determined.\n");
      else
      {
        printf("Sorted sequence determined after %d relation",r+1);
        if (r) printf("s");
        printf(": ");
        for (i=0;i<n;i++)
        {
          r=0;
          for (j=0;j<n;j++)
            r+=p[i][j];
          st[n-r-1]='A'+i;
        }
        st[n]='\0';
        printf("%s.\n",st);
      }
  }
  return 0;
}
//---------------------------------------------------------------------------
