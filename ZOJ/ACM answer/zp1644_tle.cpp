//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
int main(int argc, char* argv[])
{
  int a[32800],i,j,n;
  double tm,mx,s,ss,sm,total;
  while (scanf("%d",&n)!=EOF)
  {
    s=0;
    tm=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",a+i);
      a[i+n]=a[i];
      s+=a[i];
      tm+=s/i;
    }

    mx=tm;
    total=s;
    for (i=2;i<=n;i++)
      total+=s/i;

    for (i=2;i<=n;i++)
    {
      ss=s;
      ss-=a[i];
      tm=total-ss;
      for (j=2;j<n;j++)
      {
        ss-=a[i+j-1];
        tm-=ss/j;
        if (tm<mx)
          break;
      }
      if (tm>mx)
        mx=tm;
    }
    printf("%.2f\n",mx/n);
  }
  return 0;
}
//---------------------------------------------------------------------------
