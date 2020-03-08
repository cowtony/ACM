//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int n,i,s,j,a[110],p[1010],b[1010];
  while (scanf("%d",&n) && n>=0)
  {
    s=0;
    for (i=0;i<n;i++)
    {
      scanf("%d",a+i);
      s+=a[i];
    }
    s/=2;
    memset(p,-1,sizeof(int)*(s+2));
    p[0]=0;
    for (i=0;i<n;i++)
    {
      memset(b,-1,sizeof(int)*(s+2));
      for (j=0;j<=s;j++)
        if (p[j]>=0)
        {
          if (p[j]>b[j])
            b[j]=p[j];
          if (j-a[i]>=0 && p[j]+a[i]>b[j-a[i]])
            b[j-a[i]]=p[j]+a[i];
          else
            if (j-a[i]<0 && p[j]+j>b[a[i]-j])
              b[a[i]-j]=p[j]+j;
          if (j+a[i]<=s && p[j]>b[j+a[i]])
            b[j+a[i]]=p[j];
        }
      memcpy(p,b,sizeof(int)*(s+2));
    }
    if (p[0]<=0)
      printf("Sorry\n");
    else
      printf("%d\n",p[0]);
  }
  return 0;
}
//---------------------------------------------------------------------------
