#include<stdio.h>
#include<string.h>
int n;
int f[2000002];
int power[22];
int main()
{
    for(int i = 0; i <= 20; i++ )power[i] = (1<<i);
    memset( f, 0, sizeof( f ) );
    f[0] = 1;
    for( int j = 0; j <= 20; j++ )
        for(int i = 0; i < 2000000; i++ )
        {
            if( i+power[j] > 2000000)break;
            f[i+power[j]] += f[i];
            f[i+power[j]] %= 1000000;
        }
    
    int kcase;
    scanf("%d", &kcase);
    while( kcase-- )
    {
        scanf("%d", &n);
        printf("%d\n",f[n]);
    }
    return 0;
}