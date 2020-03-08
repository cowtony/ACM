#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1001
#define INF 30000000

long int N;
long int M;
struct edge
{
   long int a;
   long int b;
   long int cost;
}elist[500000];

unsigned long adp[MAXN];
long int status[MAXN];

int cmp(const void *A,const void *B)
{
   if ( ((edge*)A)->cost > ((edge*)B)->cost ) return 1;
   if ( ((edge*)A)->cost < ((edge*)B)->cost ) return -1;
   return 0;
}

void MST()
{
   long int i,j,start,stop;
   long int num,po;
   unsigned long dis;//最小耗费
   unsigned long minweight;//权值最小边的权值


   dis=0;num=0;po=0;
   for(i=0;i<N;i++)
      status[i]=i;//置初始集合状态

   while(num<N-1)
   {
      start = elist[po].a;
      stop  = elist[po].b;
      minweight=elist[po].cost;

      if(status[start]!=status[stop])//如果该边分属两个不同集合
      {
         dis+=minweight;
         j=status[stop];
         for(i=0;i<N;i++)
         {//将该边加入该集合
            if(status[i]==j)
               status[i]=status[start];
         }
         num++;//MST的边数加一
      }
      po++;//处理下一条最小权值边
   }
   printf("%d\n",dis);
}

int main()
{
   int sc;
   int i,j,k;
   scanf("%d",&sc);
   while(sc--)
   {
      M=0;
      memset(elist,0,sizeof(elist));
      memset(adp,0,sizeof(adp));
      scanf("%d",&N);
      for (i=0;i<N;i++)
         scanf("%d",&adp[i]);
      for (i=0; i<N; i++)
      {
         for (j=0; j<N; j++)
         {
            scanf("%d",&k); 
            if ( j>i ) 
            {
               elist[M].a=i; 
               elist[M].b=j; 
               elist[M].cost=k+adp[i]+adp[j]; 
               M++; 
            } 
         } 
      }

      qsort(elist,M,sizeof(edge),cmp);//按权值升序排列 
      MST(); 
   } 
   return 0; 
} 

//---------------------------------------------------------------------------
