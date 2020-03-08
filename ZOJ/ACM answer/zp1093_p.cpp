//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int x[100];
int y[100];
int z[100];
int a[100];
int temp;

void Swap(int &a,int &b)
{
   temp = a;
   a = b;
   b = temp;
}

int n;

int main()
{
   int i,j;
   int test = 1;
   while(scanf("%d\n",&n))
   {
      if(n == 0)
         break;
      for(i = 0; i < n; ++i)
      {
         scanf("%d %d %d\n",&x[i],&y[i],&z[i]);
         a[i] = 0;
         x[n+i] = y[i];
         y[n+i] = z[i];
         z[n+i] = x[i];
         a[n+i] = 0;
         x[2*n+i] = z[i];
         y[2*n+i] = x[i];
         z[2*n+i] = y[i];
         a[2*n+i] = 0;
      }
      for(i = 0; i < 3 * n; ++i)
         if(x[i] > y[i])
            Swap(x[i],y[i]);
      for(i = 0; i < 3 * n; ++i)
         for(j = i + 1; j < 3 * n; ++j)
            if(x[i] > x[j] || (x[i] == x[j] && y[i] > y[j]))
            {
               Swap(x[i],x[j]); Swap(y[i],y[j]); Swap(z[i],z[j]);
            }
      for(i = 0; i < 3 * n; ++i)
         for(j = i + 1; j < 3 * n; ++j)
         {
            if(x[i] < x[j] && y[i] < y[j])
            {
               if(a[j] == 0)
                  a[j] = a[i] + z[i];
               else if(a[j] < a[i] + z[i])
                  a[j] = a[i] + z[i];
            }
         }
      int max = 0;
      for(i = 0; i < 3 * n; ++i)
         if(max < z[i] + a[i])
            max = z[i] + a[i];
      printf("Case %d: maximum height = %d\n",test,max);
      ++test;
   }
   return 1;
}

//---------------------------------------------------------------------------
 