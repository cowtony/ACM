#include<stdio.h>
#include<string.h>
int prime[1500];
int n, m, k;
int f[15][1122];
int main()
{
    memset( prime, 0, sizeof( prime ) );
    for(int i = 2; i <= 100; i++ )
    {
        if(prime[i]==0)
        {
            int j = i+i;
            while( j <= 1120 )
            {
                prime[j]=1;
                j += i;
            }
        }
    }
    m = 0;
    for(int i = 2; i <= 1120; i++ )
    {
        if(prime[i]==0)prime[m++] = i;
    }
    //printf("%d\n",m);
    //for(int i = 0; i < m; i++ )printf("%d ", prime[i]);
    while( scanf("%d%d", &n, &k), n || k )
    {
        memset( f, 0, sizeof( f ) );
        f[0][0] = 1;
        
        for(int i = 0; i < m; i++ )
        {
            if( prime[i]>n)break;
            for(int z = k; z >= 1; z-- )
            {
                for(int j = n; j >= prime[i]; j-- )
                {
                    if( z > 1 && j-prime[i] == 0 )continue;
                    
                    f[z][j] += f[z-1][j-prime[i]];
                }
            }
        }
        printf("%d\n",f[k][n] );
    }
    return 0;
}