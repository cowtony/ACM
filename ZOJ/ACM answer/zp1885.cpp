//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int r[105],p[105];
  int mx,mt,t,a,b,i,j,k;
  mx=105;
  while (cin>>t>>a>>b)
  {
    cout<<'('<<t<<'^'<<a<<"-1)/("<<t<<'^'<<b<<"-1) ";
    if (t>1 && a%b==0)
    {
      for (i=1;i<=mx;i++)
        r[i]=0;
      r[1]=1;p[1]=1;
      mx=1;
      mt=1;
      for (j=1;j<a/b;j++)
      {
        for (k=1;k<=b;k++)
        {
          for (i=1;i<=mt;i++)
            p[i]*=t;
          for (i=1;i<=mt;i++)
            if (p[i]>9)
            {
              if (i==mt)
              {
                mt++;
                p[i+1]=0;
                if (mt>=100) break;
              }
              p[i+1]+=p[i]/10;
              p[i]%=10;
            }
          if (mt>100) break;
        }
        if (mt>mx) mx=mt;
        if (mx>=100) break;
        for (i=1;i<=mt;i++)
          r[i]+=p[i];
        for (i=1;i<=mx;i++)
          if (r[i]>9)
          {
            if (i==mx)
            {
              mx++;
              r[i+1]=0;
              if (mx>=100) break;
            }
            r[i+1]+=r[i]/10;
            r[i]%=10;
          }
        if (mx>=100) break;
      }
      if (mx>=100)
        cout<<"is not an integer with less than 100 digits.";
      else
        for (i=mx;i>0;i--)
          cout<<r[i];
    }
    else
      cout<<"is not an integer with less than 100 digits.";
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
