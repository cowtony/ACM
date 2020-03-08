//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int p[300],r[60][60];
void dfs(int k,int a,int b)
{
  int m,i,j,t;
  for (i=a;i<b;i++)
    if (p[i]==0)
    {
      j=++i;
      t=0;
      while (!(p[i]==-1 && t==0))
      {
        if (p[i]==0)
          t++;
        else
        if (p[i]==-1)
          t--;
        i++;
      }
      m=p[j++];
      r[k][++r[k][0]]=m;
      r[m][++r[m][0]]=k;
      dfs(m,j,i);
    }
}
int main(int argc, char* argv[])
{
  char ch;
  int s,t,d,m,i,j,k;
  while (scanf("%c",&ch)>0)
  {
    s=0;
    while (ch!='\n')
    {
      if (ch=='(')
      {
        p[s++]=0;
        scanf("%d",&p[s++]);
      }
      else
      if (ch==')')
        p[s++]=-1;
      scanf("%c",&ch);
    }
    s/=3;
    for (i=1;i<=s;i++)
      r[i][0]=0;
    dfs(p[1],2,s*3-2);
    while (s>1)
    {
      i=1;
      while (r[i][0]!=1)
        i++;
      m=r[i][1];
      if (s==2)
        printf("%d",m);
      else
        printf("%d ",m);
      j=1;
      while (r[m][j]!=i)
        j++;
      for (k=j;k<r[m][0];k++)
        r[m][k]=r[m][k+1];
      r[m][0]--;
      r[i][0]=0;
      s--;
    }
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
