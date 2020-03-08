#include<stdio.h>
#include<string.h>
int f[202][202][5];
char s[202];
int n;

int dfs(int l, int r, int w )
{
    if( f[l][r][w] >= 0 )return f[l][r][w];
    if( l > r )
    {
        if( w == 0 )return f[l][r][w] = 1;
        else return f[l][r][w] = 0;
    }
    
    if( w == 0 )
    {
        if( l > r )return f[l][r][w] = 1;
        else return f[l][r][w] = dfs(l, r, 1);
    }
    else if( w == 1 )
    {
        int t = dfs(l,r,2);
        if( t == 1 )return f[l][r][w] = 1;
        for(int i = l; i <= r; i++ )
        {
            if( s[i]==',')
            {
                t = ( dfs(l,i-1,2) && dfs(i+1,r,1) );
                //printf("%d %d %d t = %d\n",l, i, r, t );
                if( t == 1 )return f[l][r][w] = 1;
            }
        }
        return f[l][r][w] = 0;
    }
    else if( w == 2 )
    {
        int t = dfs(l,r,3);
        if( t == 1 )return f[l][r][2] = 1;
        return f[l][r][2] = dfs(l,r,4);
    }
    else if( w == 3 )
    {
        if(l==r)return f[l][r][3] = 1;
        else return f[l][r][3] = 0;
    }
    else 
    {
        if( s[l] == '{' && s[r] == '}' )
        {
            return f[l][r][4] = dfs(l+1,r-1,0);
        }
        else return f[l][r][4] = 0;
    }
}

void solve()
{
    memset( f, -1, sizeof( f ) );
    dfs(1,n,4);
    if( f[1][n][4] )printf("Set\n");
    else printf("No Set\n");
}

int main()
{
    int kcase, ts = 0;
    scanf("%d", &kcase );
    while( kcase-- )
    {
        scanf("%s",s+1);
        n = strlen(s+1);
        printf("Word #%d: ", ++ts );
        solve();
    }
    return 0;
}