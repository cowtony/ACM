#include <iostream.h>

long long max,tt,mt,i,s,w,nc,c,k,m;
long long a[10000];

void work()
{
   long t,t1,nn;
   t=1;nn=a[1];
   while (t<k)
   {
      t1=t<<1;
      if (t1>k) break;
      if (t1<k)
         if (a[t1]>a[t1+1]) 
            t1=t1+1; 
      if (nn<=a[t1]) break; 
      a[t]=a[t1]; 
      t=t1; 
   } 
   a[t]=nn; 
} 

int main() 
{ 
   while (cin>>s>>w>>c>>k>>m) 
   { 
      nc=10000/c; 
      if (10000%c!=0) nc++; 
      if (k>nc) k=nc; 
      tt=m; 
      for (i=1;i<=k;i++) 
      { 
         a[i]=tt;
         tt=tt+m;
      } 
      max=0; 
      mt=0; 
      for (i=1;i<=nc;i++) 
      { 
         tt=a[1]; 
         tt=tt+s; 
         if (tt<mt) tt=mt; 
         tt=tt+w; 
         mt=tt; 
         tt=tt+s; 
         if (max<tt) max=tt; 
         a[1]=tt; 
         work; 
      } 
      cout<<tt<<endl; 
   } 
   return 0; 
}
//---------------------------------------------------------------------------

