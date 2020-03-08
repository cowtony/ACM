#include <stdio.h>
int main()
{
    int n,m,c,sum,d,t=0,p;
    int a[21];
    int b[21];
    int i,j,k;
    while(1)
    {
        t++;
        scanf("%d%d%d",&n,&m,&c);
        if(n==0&&m==0) break;
        for(i=1;i<=n;i++)
        {
            b[i]=0;
            scanf("%d",&a[i]);
        }
        sum=0;k=0;p=0;
        for(j=0;j<m;j++)
        {
            scanf("%d",&d);
            if(b[d]==1) {b[d]=0;sum-=a[d];}
            else 
            {
                b[d]=1;
                sum+=a[d];
                if(p<sum) p=sum;
                if(sum>c) k=1;
            }
        }
        if(k==1) printf("Sequence %d\nFuse was blown.\n\n",t);
        else printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",t,p);
    }
    return 0;
}
