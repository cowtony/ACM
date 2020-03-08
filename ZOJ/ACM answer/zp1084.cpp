//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string.h>

int a[30][30];

int main(int argc, char* argv[])
{

  int s,rm,mx,n,i,j,w[30],r[30];
  char st[30];
  while (scanf("%d",&n) && n)
  {
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        a[i][j]=0;

    for (i=0;i<n;i++)
    {
      w[i]=0;
      scanf("%s",st);
      for (j=2;j<strlen(st);j++)
      {
        a[i][st[j]-'A']=1;
        a[st[j]-'A'][i]=1;
      }
      r[i]=strlen(st)-2;
    }

    s=0;
    while (1)
    {
      rm=-1;  mx=-1;
      for (i=0;i<n;i++)
        if (w[i]==0)
          if (r[i]>mx)
          {
            rm=i;
            mx=r[i];
          }
      if (rm==-1)
        break;

      w[rm]=++s;
      for (i=0;i<n;i++)
        if (w[i]==0)
        {
          for (j=0;j<n;j++)
            if (w[j]==s && a[j][i]==1)
              break;
          if (j==n)
            w[i]=s;
        }
    }
    if (s==1)
      printf("%d channel needed.\n",s);
    else
      printf("%d channels needed.\n",s);
  }
  return 0;
}
//---------------------------------------------------------------------------
