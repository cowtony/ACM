#include <stdio.h>
int main()
{
    int cas;
    int i,j;
    int a[201];
    int s,d;
    int n,max,t;
    scanf("%d",&cas);
    while(cas--)
    {
        for(i=1;i<200;i++)
        {
            a[i]=0;
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&s,&d);
            if(s%2==0) s--;
            if(d%2==0) d--;
            if(s>d) {t=s;s=d;d=t;}
            for(j=(s+1)/2;j<=(d+1)/2;j++)
                a[j]++;
        }
        max=0;
        for(i=0;i<200;i++)
        {
            if(a[i]>max) max=a[i];
        }
        printf("%d\n",max*10);
    }
    return 0;
}


