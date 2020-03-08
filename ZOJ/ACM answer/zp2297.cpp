//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int n,bos,pot,t,p[21],cst[21],itr[21];

void dfs(int m)
{
  if (m==n)
  {
    if (pot>=bos)
    {
      printf("clear!!!\n");
      t=1;
    }
  }
  else
  {
    int i,r;
    for (i=1;i<n;i++)
      if (p[i])
      {
        if (pot>=cst[i])
        {
          p[i]--;
          r=pot;
          pot+=itr[i];
          if (pot>100)
            pot=100;
          dfs(m+1);
          if (t)  return;
          pot=r;
          p[i]++;
        }
      }
  }
}
int main(int argc, char* argv[])
{
  int i,j,s;
  while (scanf("%d",&n)!=EOF)
  {
    s=100; t=0;
    for (i=1;i<n;i++)
    {
      scanf("%d%d",cst+i,itr+i);
      itr[i]-=cst[i];
      s+=itr[i];
      if (cst[i]>100)
        t=1;
    }
    scanf("%d",&bos);
    if (t || s<bos)
    {
      printf("try again\n");
      continue;
    }
    for (i=1;i<n;i++)
      p[i]=1;

    for (i=1;i<n-1;i++)
      for (j=i+1;j<n;j++)
        if (itr[i]>itr[j])
        {
          t=cst[i];    cst[i]=cst[j];    cst[j]=t;
          t=itr[i];    itr[i]=itr[j];    itr[j]=t;
        }
    for (i=1;i<n-1;i++)
      if (cst[i]==cst[i+1] && itr[i]==itr[i+1])
      {
        p[i+1]=p[i]+1;
        p[i]=0;
      }

    pot=100;
    t=0;

    dfs(1);

    if (t==0)
      printf("try again\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
