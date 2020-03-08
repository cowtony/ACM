#include <stdio.h>
#include <string.h>

int x , y;

void solve()
{
    if(x == y || x == y + 2)
    {
        int ret;
        if(x == y)
        {
            if(x % 2 == 0) ret = x * 2;
            else ret = x * 2 - 1;
        }
        else
        {
            if(x % 2 == 0) ret = x + y;
            else ret = x + y - 1;
        }                        
        printf("%d\n" , ret);
    }
    else
    {
        puts("No Number");
    }
}

int main()
{
    int T;
    scanf("%d" , &T);

    while(T--)
    {
        scanf("%d%d" , &x , &y);
        solve();
    }

    return 0;
}
