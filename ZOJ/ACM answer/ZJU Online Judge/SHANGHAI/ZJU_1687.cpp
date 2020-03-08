#include <stdio.h>
#include <string.h>

#define MAXS 8194

int n , S;
int M[2][16];
int f[MAXS][16][2];

void init()
{
    int i;
    scanf("%d" , &S);
    for(i=0; i<n; i++)
    {
        scanf("%d%d" , &M[0][i] , &M[1][i]);
    }
}

int dp(int S , int id , int person)
{
    if(f[S][id][person] < 0)
    {
        if(S == 1) f[S][id][person] = 0;
        else
        {
            f[S][id][person] = 0;
            for(int i=1; i<S && i<=M[person][id]; i++)
            {
                if(!dp(S - i , (id + person) % n , 1 - person))
                {
                    f[S][id][person] = 1;
                    break;
                }
            }
        }
    }
    return f[S][id][person];
}

void solve()
{
    memset(f , 0xff , sizeof(f));
    printf("%d\n" , dp(S , 0 , 0));
}

int main()
{
    freopen("in.txt" , "r" , stdin); 

    while(1)
    {
        scanf("%d" , &n);
        if(n == 0) break;

        init();
        solve();
    }

    return 0;
}
