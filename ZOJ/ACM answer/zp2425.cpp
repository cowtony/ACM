//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>

int main()
{
  int n,m,i,h;
  int a[50010],p[50010];

  i=1;
  while (i<50001)
    p[i++]=i*(i+1)/2;

  while (scanf("%d%d",&n,&m) && n+m!=-2)
  {
    if (m==0)
      h=0;
    else
      for (i=0;i<=n;i++)
        if (m>p[i] && m<=p[i+1])
        { h=i+1; break; }
    for (i=1;i<n-h;i++)
      printf("%d ",i);
      //cout<<i<<' ';
    if (m==0) printf("%d",n); //cout<<n;
    else      printf("%d ",n-h*(h+1)/2+m);
    //cout<<n-h*(h+1)/2+m<<' ';

    for (i=h+1;i>0;i--)
      if (i+n-h-1!=n-h*(h+1)/2+m)
        if (i==1)
          printf("%d",i+n-h-1);
          //cout<<i+n-h-1;
        else
          printf("%d ",i+n-h-1);
          //cout<<i+n-h-1<<' ';
    printf("\n");
    //cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 