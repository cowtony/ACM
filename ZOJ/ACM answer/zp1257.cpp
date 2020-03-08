//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  int i,v,t,n,m,s,p[25]={0},r[25]={0};
  for (i=1;i<21;i++)
    r[i]=0;
  s=0;
  while (scanf("%d",&n) && n<99)
  {
    p[++s]=n;
    r[n]=s;
  }

  v=0;
  while (scanf("%d",&n)>0)
  {
    m=n;
    while (r[(n-v+219)%20+1]<=0)
      v++;
    r[(n-v+219)%20+1]=-m;
  }

  for (i=1;i<=s;i++)
    if (r[p[i]]<0)
      printf("Original position %d parked in %d\n",p[i],-r[p[i]]);
    else
      printf("Original position %d did not park\n",p[i]);
  return 0;
}
//---------------------------------------------------------------------------
