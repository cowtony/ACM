#include <stdio.h>
#include <string.h>

int s , x , y , dx , dy;

bool check_white()
{
    if(x % s == 0 || y  % s == 0) return 0;
    return ((x / s) % 2) != ((y / s) % 2);
}

void solve()
{
    for(int i=0; i<10*s; i++)
    {
        if(check_white())
        {
            printf("After %d jumps the flea lands at (%d, %d).\n" , i , x , y);
            return;
        }
        x += dx; y += dy;
    }
    puts("The flea cannot escape from black squares.");
}

int main()
{
    while(1)
    {
        scanf("%d" , &s);
        if(s == 0) break;
        scanf("%d%d%d%d" , &x , &y , &dx , &dy);
        
        solve();
    }   
    
    return 0;
}
