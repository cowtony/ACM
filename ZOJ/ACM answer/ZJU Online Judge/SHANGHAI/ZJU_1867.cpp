#include <stdio.h>
#include <string.h>

int s , d;
int v[15];

int sum(int k)
{
    int ret = 0;
    for(int i=0; i<5; i++)
    {
        ret += v[k-i];
    }
    return ret;
}

void solve()
{
    int i , j;

    for(i=0; i<12; i++)
        v[i] = s;
    
    for(i=4; i<12; i++)
    {
        while(sum(i) >= 0)
        {
            for(j=0; j<5; j++)
            {
                if(v[i-j] == s)
                {
                    v[i-j] = -d;
                    break;
                }
            }
        }
    }

    int ret = 0;
    for(i=0; i<12; i++) ret += v[i];
    if(ret < 0) puts("Deficit");
    else printf("%d\n" , ret);
}

int main()
{
    while(scanf("%d%d" , &s , &d) > 0)
    {
        solve();
    }

    return 0;
}