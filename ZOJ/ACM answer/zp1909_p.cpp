#include <stdio.h>
#include <string.h>
#include <math.h>

int i,j,k,m,n,N,sum,side,tot;
int s[30];
char d[32*1024*1024];

int doit(int n, int sum, int mask) {
   int i,j,k;
   if (d[mask]) return 0;
   if (sum > side) return 0;
   if (sum == side) sum = 0;
   if (n == m && !sum) return 1;
   d[mask] = 1;
   for (i=0;i<m;i++) {
      if (mask & (1<<i)) continue; // already used
      if (doit(n+1,sum+s[i],mask | (1<<i))) {
         tot += s[i];
         return 1;
      }
   }
   return 0;
}
   

main(){
   scanf("%d",&N);
   while(N--){
      scanf("%d",&m);
      for (i=0;i<m;i++) scanf("%d",&s[i]);
      for (i=sum=0;i<m;i++) sum += s[i];
      side = sum/4;
      if (side * 4 != sum) {
         printf("no\n");
         continue;
      }
      memset(d, 0, 1<<m);

      tot = 0;
      if (doit(0,0,0)) printf("yes\n");
      else printf("no\n");
   }
}
