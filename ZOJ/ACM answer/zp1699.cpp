//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
   int n,s,c,i,j,k,t,cr[202],p[5];
   string st,sc[202];
   cin>>n>>s>>c;
   while (n)
   {
     cin>>st;
     for (i=1;i<=c;i++)
     {
       cin>>sc[i];
       cr[i]=sc[i].length();
     }
     k=1;t=0;
     for (i=1;i<=n;i++)
       p[i]=0;
     while (k<=c)
     {
       for(i=1;i<=n;i++)
       {
         for (j=p[i]+1;j<=s;j++)
           if (st[j-1]==sc[k][0])
           { p[i]=j; break; }
         if (j>=s)
         { t=1; break; }
         else
           if (cr[k]==2)
           {
             for (j=p[i]+1;j<=s;j++)
               if (st[j-1]==sc[k][1])
               { p[i]=j; break; }
             if (j>=s)
             { t=1; break; }
           }
         if (t)
           break;
         k++;
         if (k>c)
           break;
       }
       if (t || k>c)
         break;
     }
     if (t)
       cout<<"Player "<<i<<" won after "<<k<<" cards."<<endl;
     else
       cout<<"No player won after "<<c<<" cards."<<endl;
     cin>>n>>s>>c;
   }
   return 0;
}
//---------------------------------------------------------------------------
