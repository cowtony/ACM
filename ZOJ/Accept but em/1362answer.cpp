#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
     int n,m,t,Case=0;
     int a[1001];
     int i,j,k;
     while(scanf("%d%d",&m,&n)!=EOF&&(n||m))
     {
         memset(a,0,sizeof(a));
         for(i=0;i<n;i++)
         {
              scanf("%d",&t);
              a[t]=1;
         }
         for(i=1;!a[i];i++);
         for(j=m*n;j>=i;j--)
         {
              if(a[j]==0)
              {
                   for(k=j;k>=i;k--)
                   {
                       if(a[k]==1)
                       {
                            a[k]=2;
                            break;
                       }
                   }
              }
         }
         t=0;
         for(j=i;j<=m*n;j++)
         {
              if(a[j]==1)
                   t++;
         }
         printf("Case %d: %d\n",++Case,t);
     }
}