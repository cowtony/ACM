#include <stdio.h>
#include <string>
using namespace std;
int n,a[4],b[4]={1,5,10,25};
void cal(int mx)
{
  int i,j,k,l,sm=0,v=0;
  for (i=0;i<=a[3];i++)
  {
    if (i) {  sm+=b[3]; v++; }
    if (sm<=n)
    for (j=0;j<=a[2];j++)
    {
      if (j) {  sm+=b[2]; v++; }
      if (sm<=n)
      for (k=0;k<=a[1];k++)
      {
        if (k) {  sm+=b[1]; v++; }
        if (sm<=n)
        for (l=0;l<=a[0];l++)
        {
          if (l) {  sm+=b[0]; v++; }
          if (sm==n && v==mx)
          {
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",l,k,j,i);
            return;
          }
        }
        sm-=b[0]*a[0];
        v-=a[0];
      }
    sm-=b[1]*a[1];
    v-=a[1];
    }
    sm-=b[2]*a[2];
    v-=a[2];
  }
}
int main(int argc, char* argv[])
{
  int i,j,k,p[10010],q[10010];

  while (scanf("%d%d%d%d%d",&n,a,a+1,a+2,a+3)!=EOF && n)
  {
    memset(p,0,sizeof(int)*(n+2));
    p[0]=1;
    for (i=0;i<4;i++)
    {
      memset(q,0,sizeof(int)*(n+2));
      for (k=0;k<=n;k++)
        if (p[k])
          for (j=0;j<=a[i];j++)
          {
            if (k+b[i]*j<=n && p[k]+j>q[k+b[i]*j])
             q[k+b[i]*j]=p[k]+j;
          }
      memcpy(p,q,sizeof(int)*(n+2));
    }
    if (p[n])
    {
      cal(p[n]-1);
    }
    else
      printf("Charlie cannot buy coffee.\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
