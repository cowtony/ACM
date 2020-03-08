//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//#include<iostream>
//using namespace std;
#include <stdio.h>

int a[3005],b[3005],num,con,j,k,l,n,t;

int main()
{
   while(scanf("%d",&n)!=EOF)
   {
      num=0;con=0;
      for(l=0;l<=n;l++)
         a[l]=b[l]=0;
      for(j=0;j<n;j++)
      {
         for(k=1;k<=n;k++)
         {
            scanf("%d",&t);
            if(t==0)
            {
               if(b[k-1]!=0)
               {
                  b[k]=b[k-1];
                  if (a[k]!=0 && a[k]!=b[k])
                     if(a[k]>b[k])
                     {
                        t=a[k];
                        num--;
                        for(l=0;l<=n;l++)
                           if(a[l]==t)
                              a[l]=b[k];
                     }
                     else
                     {
                        t=b[k];
                        num--;
                        for(l=0;l<=n;l++)
                           if(b[l]==t)
                              b[l]=a[k];
                     }
               }
               else
                  if(a[k]!=0)
                     b[k]=a[k];
                  else
                  {
                     b[k]=++con;
                     num++;
                  }
            }
            else  //(t!=0)
               b[k]=0;
         }
         for(l=0;l<=n;l++)
            a[l]=b[l];
      }
      printf("%d\n",num);
      //cout << num << endl ;
   }
   return 0;
}
//---------------------------------------------------------------------------
