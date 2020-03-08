//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;

struct typ
{
   char t[31];
} st[50010];

int a[50010];

void findit(int p, int q)
{
   if (p<q)
   {
      int i,mx=0,r=0;
      for (i=p;i<q;i++)
         if (a[i]>mx)
         {
            mx=a[i];
            r=i;
         }
      if (r>p)
      {
         cout<<'(';
         findit(p,r);
         cout<<')';
      }
      cout<<st[r].t<<'/'<<a[r];
      if (r<q-1)
      {
         cout<<'(';
         findit(r+1,q);
         cout<<')';
      }
   }
}
int main(int argc, char* argv[])
{
   int n,i,s;
   char ch;
   cin>>n;
   while (n)
   {
      for (i=0;i<n;i++)
      {
         cin>>ch;
         s=0;
         while (ch!='/')
         {
            st[i].t[s++]=ch;
            cin>>ch;
         }
         st[i].t[s]=NULL;
         cin>>a[i];
      }
      cout<<'(';
      findit(0,n);
      cout<<')';
      cout<<endl;
      cin>>n;
   }
   return 0;
}
//---------------------------------------------------------------------------
