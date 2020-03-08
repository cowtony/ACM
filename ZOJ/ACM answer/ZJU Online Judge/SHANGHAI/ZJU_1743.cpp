#include <stdio.h>
#include <string.h>

int N;

void Init()
{    
}

void Solve()
{
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    
    while(1)
    {
        scanf("%d" , &N);
        if(N == 0) break;
        
        Init();
        Solve();
    }
    
    return 0;
}
