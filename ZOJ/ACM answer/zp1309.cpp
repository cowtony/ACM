//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>h>
#include <math.h>
#include <iomanip.h>

int main(int argc, char* argv[])
{
  int n,i,j,p[510];
  long double x0,x1,x2,y0,y1,y2,r,d,m,b,k,a,c,lx[510],rx[510];

  cout<<setiosflags(ios::fixed)<<setprecision(2);
  cin>>n;
  while (n)
  {
    cin>>x0>>y0;
    for (i=0;i<n;i++)
    {
      cin>>x1>>y1>>d;
      r=sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0));
      r=sqrt(r*r-d*d);

      k=-(x1-x0)/(y1-y0);
      m=(d*d-r*r+x0*x0-x1*x1+y0*y0-y1*y1)*0.5/(y0-y1)-y1;

      c=m*m+x1*x1-d*d;
      b=2*k*m-2*x1;
      a=k*k+1;

      x1=(-b-sqrt(b*b-4*a*c))*0.5/a;
      x2=(-b+sqrt(b*b-4*a*c))*0.5/a;

      m+=y1;
      y1=x1*k+m;
      y2=x2*k+m;

      lx[i]=(x0-x1)*(-y1)/(y0-y1)+x1;
      rx[i]=(x0-x2)*(-y2)/(y0-y2)+x2;
    }

    for (i=0;i<n-1;i++)
      for (j=i+1;j<n;j++)
        if (lx[i]-lx[j]>0)
        {
          m=lx[i]; lx[i]=lx[j]; lx[j]=m;
          m=rx[i]; rx[i]=rx[j]; rx[j]=m;
        }

    for (i=0;i<n;i++)
      p[i]=1;

    for (i=0;i<n-1;i++)
      if (p[i])
        for (j=i+1;j<n;j++)
          if (p[j])
            if (lx[j]-rx[i]<=0)
            {
              if (rx[j]-rx[i]>0)
                rx[i]=rx[j];
              p[j]=0;
            }
   for (i=0;i<n;i++)
      if (p[i])
        cout<<lx[i]<<' '<<rx[i]<<endl;

    cout<<endl;
    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
