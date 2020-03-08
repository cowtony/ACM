#include <stdio.h>
#include <stdlib.h>

int cmp(void const *a,void const *b)
{
  int x=*(int *)a,y=*(int *)b;
  if (x>y)  return 1;
  return -1;
}

int num,quo,d,s,a[7],p[7],v[8],q[10],arr[500];

void cal(int k)
{
  if (k==0)
  {
    arr[s++]=num;
  }
  else
  {
    int i;
    for (i=v[k];i<10;i+=d)
      if (q[i])
      {
        q[i]=0;
        num+=i*quo;
        quo*=10;
        cal(k-1);
        quo/=10;
        num-=i*quo;
        q[i]=1;
      }
  }
}
void dfs(int m)
{
  if (m==d)
  {
    int i;
    for (i=1;i<d;i++)
    {
      v[a[i-1]+1]=(a[i]-a[i-1]+d)%d;
    }
    v[a[d-1]+1]=(a[0]-a[d-1]+d)%d;

    num=0;
    quo=1;
    for (i=1;i<10;i++)
      q[i]=1;
    cal(d);
  }
  else
  {
    int i;
    for (i=1;i<d;i++)
      if (p[i])
      {
        p[i]=0;
        a[m]=i;
        dfs(m+1);
        p[i]=1;
      }
  }
}
int main(int argc, char* argv[])
{
  int t,i,n,cs=0;
  s=0;
  for (d=2;d<8;d++)
  {
    p[0]=0;
    for (i=1;i<d;i++)
      p[i]=1;
    a[0]=0;
    t=s;
    dfs(1);
    qsort(arr+t,s-t,sizeof(int),cmp);
  }
  //printf("%d\n",s);
  arr[s]=11111111;
  while (scanf("%d",&n) && n)
  {
    for (i=0;i<s;i++)
      if (n<=arr[i])
        break;
    printf("Case %d: %d\n",++cs,arr[i]);
  }
  return 0;
}
//---------------------------------------------------------------------------
