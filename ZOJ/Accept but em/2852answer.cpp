#include<stdio.h>
#include<string.h>
int f[102][22][22][22];
char s[105][3];
int n;

int main()
{
    while( scanf("%d", &n), n )
    {
        for(int i = 1; i <= n; i++ )
        {
            scanf("%s",s[i]);
        }
        memset( f, -1, sizeof( f ) );
        f[0][0][0][0] = 0;
        for(int i = 1; i <= n; i++ )
        {
            for(int x = 21; x >= 0; x-- )
            {
                for(int y = 21; y >= 0; y-- )
                {
                    for(int z = 21; z >= 0; z-- )if( f[i-1][x][y][z] >= 0 )
                    {
                        if(s[i][0]=='F')
                        {
                            if(x <= 20 && f[i][0][y][z] < f[i-1][x][y][z] + 150 )
                            {
                                f[i][0][y][z] = f[i-1][x][y][z] + 150;
                            }
                            if( y <= 20 && f[i][x][0][z] < f[i-1][x][y][z] + 250 )
                            {
                                f[i][x][0][z] = f[i-1][x][y][z] + 250;
                            }
                            if( z <=20 && f[i][x][y][0] < f[i-1][x][y][z] + 350 )
                            {
                                f[i][x][y][0] = f[i-1][x][y][z] + 350;
                            }
                        }
                        else
                        {
                            int t = 0;
                            if( s[i][0] == 'A' )t = 1;
                            else if(s[i][0]<='9' && s[i][0] >= '2' )t = s[i][0]-'0';
                            else t = 10;
                            
                            if(t + x <= 20 && f[i][t+x][y][z] < f[i-1][x][y][z] + 50 )
                            {
                                f[i][x+t][y][z] = f[i-1][x][y][z] + 50;
                            }
                            else if(t + x == 21 && f[i][0][y][z] < f[i-1][x][y][z] + 150 )
                            {
                                f[i][0][y][z] = f[i-1][x][y][z] + 150;
                            }
                            else if(x <= 20 && t + x > 21 && f[i][21][y][z] < f[i-1][x][y][z] + 50 )
                            {
                                f[i][21][y][z] = f[i-1][x][y][z] + 50;
                            }
                            
                            
                            if( t + y <= 20 && f[i][x][t+y][z] < f[i-1][x][y][z] + 50 )
                            {
                                f[i][x][y+t][z] = f[i-1][x][y][z] + 50;
                            }
                            else if( t+y == 21 && f[i][x][0][z] < f[i-1][x][y][z] + 250 )
                            {
                                f[i][x][0][z] = f[i-1][x][y][z] + 250;
                            }
                            else if( y <= 20 && t+y > 21 && f[i][x][21][z] < f[i-1][x][y][z] + 50 )
                            {
                                f[i][x][21][z] = f[i-1][x][y][z] + 50;
                            }
                            
                            
                            if( t + z <=20 && f[i][x][y][t+z] < f[i-1][x][y][z] + 50 )
                            {
                                f[i][x][y][z+t] = f[i-1][x][y][z] + 50;
                            }
                            else if( t + z == 21 && f[i][x][y][0] < f[i-1][x][y][z] + 350 )
                            {
                                f[i][x][y][0] = f[i-1][x][y][z] + 350;
                            }
                            else if( z <= 20 && t + z > 21 && f[i][x][y][21] < f[i-1][x][y][z] + 50 )
                            {
                                f[i][x][y][21] = f[i-1][x][y][z] + 50;
                            }
                        }
                    }
                }
            }
        }
        int ans = -1;
        for(int i = 1; i <= n; i++ )
        {
            for(int x = 0; x <= 21; x++ )
            {
                for(int y = 0; y <= 21; y++ )
                {
                    for(int z = 0; z <= 21; z++ )
                    {
                        if(f[i][x][y][z] > ans )ans = f[i][x][y][z];
                    }
                }
            }
        }
        printf("%d\n", ans );
    }
    return 0;
}