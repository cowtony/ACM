#include<stdio.h>
#include<string.h>

double f[1<<16][16];

int flag[1<<16];
int cnt[1<<16];

double sp[16];

int pow[16];

double map[16][16];

int must[16];

int n, m, K;

int abs( int a )
{
    return a > 0 ? a : -a;
}

void DP()
{
    int i, j, k, s, t;
    
    for( i = 0; i < pow[n]; i++ )
    {
        flag[i] = 0;
        cnt[i] = 0;
        for( j = 0; j < n; j++ )
        {
            f[i][j] = -1;
        }
    }
    
    f[1][0] = sp[0];
    
    
    for( i = 2; i < pow[n]; i++ )
    {
        for( j = 0; j < n; j++ )if( (i&pow[j]) )
        {
            
            for( k = 0; k < n; k++ )if( (i&pow[k]) && map[j][k] > 0 )
            {
                t = i-pow[k];
                
                if( f[t][j] < 0 )continue;
                
                if( f[i][k] < 0 || f[i][k] > f[t][j]+map[j][k]+sp[k] )
                {
                    f[i][k] = f[t][j]+map[j][k]+sp[k];
                }
            }     
        }
    }
    
    for( i = 1; i < pow[n]; i++ )
    {
        for( j = 0; j < m; j++ )
        {
            if( (i&pow[must[j]]) == 0 )break;
        }
        
        if( j >= m )
        {
            flag[i] = 1;
        }
        else continue;
        
        for( j = 0; j < n; j++ )
        {
            if( (i&pow[j]) )cnt[i]++;
        }
        
    }
    
    int M = -1;
    for( i = 1; i < pow[n]; i++ )if( flag[i] )
    {
        for( k = 0; k < n; k++ )
        {
            if( f[i][k] > 0 && f[i][k]+map[k][1] <= K*12 )
            {
                if( cnt[i] > M )M = cnt[i];
                break;
            } 
        } 
    }
    
    if( M < 0 )printf( "No Solution\n" );
    else printf( "%d\n", M );

}


int main()
{
    int i, j, k;
    int x, y, kind;
    double len, s;
    for( i = 0; i <= 15; i++ )
    {
        pow[i] = 1<<i;
    }
    while( scanf( "%d %d %d", &n, &m, &K ) != EOF )
    {
        if( n == 0 && m == 0 && K == 0 )break;
        
        for( i = 0; i < m; i++ )
        {
            scanf( "%d", must+i );
            must[i]--;
        } 
        
        for( i = 0; i < n; i++ )
        {
            scanf( "%lf", sp+i );
        }
         
        for(i = 0; i < n; i++ )
        {
            for( j = 0; j < n; j++ )
            {
                map[i][j] = -1;
            }
        }
        while( 1 )
        {
            scanf( "%d %d %lf %d", &x, &y, &len, &kind );
            if( x == 0 && y == 0 && kind == 0 && len == 0 ) break;
            x--,y--;
            if( kind == 0 )
            {
                s = len/80;
            }
            else if( kind == 1 )
            {
                s = len/120;
            }
            
            if( map[x][y] < 0 || map[x][y] > s )
            {
                map[x][y] = map[y][x] = s;
            }
        }
        
        for( k = 0; k < n; k++ )
        {
            for( i = 0; i < n; i++ )
            {
                for( j = 0; j < n; j++ )
                {
                    if( map[i][k] > 0 && map[k][j] > 0 && ( map[i][j] < 0 || map[i][j] > map[i][k]+map[k][j] ) )
                    {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
        
        DP();
    
    }
    return 0;
    
}