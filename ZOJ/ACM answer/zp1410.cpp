//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
//#include <math.h>

int main(int argc, char* argv[])
{
   long long x,a[31300];
   short b[150000];
   int i,n,s,I,N;
   a[0]=0;
   for (i=1;i<10;i++)
      a[i]=a[i-1]+i;
   for (i=10;i<100;i++)
      a[i]=a[i-1]+i*2-9;
   for (i=100;i<1000;i++)
      a[i]=a[i-1]+i*3-108;
   for (i=1000;i<10000;i++)
      a[i]=a[i-1]+i*4-1107;
   for (i=10000;i<31300;i++)
      a[i]=a[i-1]+i*5-11106;

   for (i=1;i<10;i++)
      b[i]=i;
   s=10;
   for (i=10;i<100;i++)
   {
      b[s++]=i/10;
      b[s++]=i%10;
   }
   for (i=100;i<1000;i++)
   {
      b[s++]=i/100;
      b[s++]=i/10%10;
      b[s++]=i%10;
   }
   for (i=1000;i<10000;i++)
   {
      b[s++]=i/1000;
      b[s++]=i/100%10;
      b[s++]=i/10%10;
      b[s++]=i%10;
   }
   for (i=10000;i<31300;i++)
   {
      b[s++]=i/10000;
      b[s++]=i/1000%10;
      b[s++]=i/100%10;
      b[s++]=i/10%10;
      b[s++]=i%10;
   }
   //cout<<s<<endl;

   cin>>N;
   for (I=0;I<N;I++)
   {
      cin>>x;
      //n=(sqrt(x+1)-1)/2-1;
      //cout<<n<<endl;
      for (i=0;i<31300;i++)
         if (a[i]<x && x<=a[i+1])
            break;
      //cout<<i<<endl;
      x-=a[i];
      cout<<b[x]<<endl;
   }
   return 0;
}
//---------------------------------------------------------------------------
