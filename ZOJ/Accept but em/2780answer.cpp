#include<stdio.h>
#include<string.h>
int n, all;
unsigned int f[1003];
int a[31];
int flag[31];
int main()
{
    int kcase, sum, ts = 0;
    scanf("%d",&kcase);
    while( kcase-- )
    {
        sum = 0;
        scanf("%d%d", &n, &all );
        for(int i = 0; i < n; i++ )
        {
            scanf("%d",a+i);
            sum += a[i];
        }
        sum = (sum>all?all:sum);
        unsigned int ans = 0;
        for(int i = sum; i >= 1; i-- )
        {
            memset(flag,0,sizeof(flag));
            int t = 0;
            for(int j = 0; j < n; j++ )
            {
                if((all-i)>=a[j])t += a[j];
            }
            if( t > i )break;
            for(int j = t; j <= i; j++ )f[j] = 0;
            f[t] = 1;
            
            for(int j = 0; j < n; j++ )if( (all-i) < a[j] )
            {
                for(int k = i; k >= (a[j]+t); k-- )
                {
                    f[k] += f[k-a[j]];
                }
            }
            ans += f[i];
        }
        printf("%d %u\n",++ts, ans);
    }
    return 0;
}
