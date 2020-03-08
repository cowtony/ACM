//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

int main(int argc, char* argv[])
{
   int n,m,s,i,j,k;
   int a[10],ty[10],ky[10],ma[11],mb[11];

   ty[0]=0;
   ky[0]=1;k=1;
   for (i=1;i<=6;i++)
   {
      ty[i]=i*k;
      k*=10;
      ky[i]=ky[i-1]+k;
   }

   cin>>n;
   while (n)
   {
      for (j=0;j<10;j++)
         ma[j]=0;
      for (j=0;j<10;j++)
         mb[j]=0;
      n--;
      m=n;s=0;
      while (m)
      {
         a[s++]=m%10;
         m/=10;
      }
      k=1;
      for (i=0;i<s;i++)
      {
         ma[a[i]]+=(n-n/k*k)+1;
         for (j=0;j<a[i];j++)
            ma[j]+=k;
         for (j=0;j<10;j++)
            ma[j]+=ty[i]*a[i];
         k*=10;
      }
      ma[0]-=ky[s-1];




      cin>>n;
      m=n;s=0;
      while (m)
      {
         a[s++]=m%10;
         m/=10;
      }
      k=1;
      for (i=0;i<s;i++)
      {
         mb[a[i]]+=(n-n/k*k)+1;
         for (j=0;j<a[i];j++)
            mb[j]+=k;
         for (j=0;j<10;j++)
            mb[j]+=ty[i]*a[i];
         k*=10;
      }
      mb[0]-=ky[s-1];
      cout<<mb[0]-ma[0];
      for (i=1;i<10;i++)
         cout<<' '<<mb[i]-ma[i];
      cout<<endl;


      cin>>n;
   }
   return 0;
}
//---------------------------------------------------------------------------
