//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  int a[8],r[110],p[110];
  int cas,s,i,t,l,j,k;
  cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];
  cas=0;
  while (a[1]+a[2]+a[3]+a[4]+a[5]+a[6])
  {
    s=0;
    for (i=1;i<=6;i++)
      s+=i*a[i];
    if (s%2)
      t=0;
    else
    {
      s/=2;
      if (s>60)
      {
        s%=60;
        for (i=1;i<7;i++)
          a[i]%=(60/i);
      }
      memset(r,0,sizeof(int)*100); r[0]=1;
      memset(p,0,sizeof(int)*100); p[0]=1;
      for (i=1;i<7;i++)
        if (a[i])
        {
          k=0;
          while (k<=s)
          {
            if (r[k]==1)
              for (j=1;j<=a[i];j++)
                if (k+j*i<=s)
                  p[k+j*i]=1;
                else
                  break;
            k++;
          }
          memcpy(r,p,sizeof(int)*100);
        }
      t=r[s];
    }
    cout<<"Collection #"<<++cas<<":"<<endl;
    if (t==1)
      cout<<"Can be divided."<<endl;
    else
      cout<<"Can't be divided."<<endl;
    cout<<endl;
    cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];
  }
  return 0;
}
//---------------------------------------------------------------------------
