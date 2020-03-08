//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
#include <string.h>

struct matr
{
  int xc,xr;
};
struct matr mtr[26];

char st[1000];
long long total;
void dfs(int a,int b,int &r,int &c)
{
  for (int i=a;i<=b;i++)
  {
    if (st[i]=='(')
    {
      i++;
      int t=0,j=i;
      while (!(st[i]==')' && t==0))
      {
        if (st[i]=='(')
          t++;
        else
        if (st[i]==')')
          t--;
        i++;
      }

      int rr=-1,cc=r;
      dfs(j,i-1,rr,cc);
      if (total<0)
        return;
      if (r<0)
      {
        r=rr;
        c=cc;
      }
      else
      {
        if (c==rr)
        {
          total+=r*c*cc;
          c=cc;
        }
        else
          if (rr!=-1)
            total=-1;
      }
    }
    else
    {
      if (mtr[st[i]-'A'].xc==-1)
        total=-1;
      else
      if (r<0)
      {
        r=mtr[st[i]-'A'].xr;
        c=mtr[st[i]-'A'].xc;
      }
      else
      {
        if (c==mtr[st[i]-'A'].xr)
        {
          total+=r*c*mtr[st[i]-'A'].xc;
          c=mtr[st[i]-'A'].xc;
        }
        else
          total=-1;
      }
    }
    if (total<0)
      return;
  }
}
int main(int argc, char* argv[])
{
  int i,n,r,c;
  for (i=0;i<26;i++)
    mtr[i].xr=mtr[i].xc=-1;
  scanf("%d",&n);
  for (i=0;i<n;i++)
  {
    scanf("%s",st);
    scanf("%d%d",&mtr[st[0]-'A'].xr,&mtr[st[0]-'A'].xc);
  }
  while (scanf("%s",st)>0)
  {
    total=0;
    r=-1;
    dfs(0,strlen(st)-1,r,c);
    if (total<0)
      printf("error\n");
    else
      printf("%d\n",total);
  }
  return 0;
}
//---------------------------------------------------------------------------
