#include <stdio.h>
#include <string.h>

const int MaxLen = 10010;

int K , n;
int list[MaxLen];
bool mark[MaxLen];
int empty;

void init()
{
    scanf("%d%d" , &K , &n);
    memset(list , 0 , sizeof(list));

    int i , p , k , key;
    p = 0;
    for(i=0; i<n; i++)
    {
        scanf("%d" , &k);
        while(k--)
        {
            scanf("%d" , &key);
            list[key] = ++p;
        }
    }
}

void swap(int a , int b)
{
    printf("%d %d\n" , a , b);
    int t = list[a];
    list[a] = list[b];
    list[b] = t;
}

bool outed;

int path[MaxLen];
int len;

void find(int st)
{
    if(list[st] == st)
    {
        mark[st] = 1;
        return ;
    }

    outed = 1;
    len = 1; path[1] = st;
    
    int next = list[st];
    mark[st] = 1;
    while(next != st && next != 0)
    {
        path[++len] = next;
        mark[next] = 1;
        next = list[next];
    }

    if(next == 0)
    {
        for(int i=len; i>1; i--)
        {
            swap(path[i-1] , path[i]);            
        }

        empty = st;
    }
    else
    {
        swap(path[len] , empty);
        for(int i=len; i>1; i--)
            swap(path[i-1] , path[i]);
        swap(empty , st);
    }
}

void solve()
{
    int i;

    for(i=1; i<=K; i++)
    {
        if(list[i] == 0)
        {
            empty = i;
            break;
        }
    }

    memset(mark , 0 , sizeof(mark));
    outed = 0;
    for(i=1; i<=K; i++)
    {
        if(list[i] && !mark[i])
        {
            find(i);
        }
    }

    if(!outed)
    {
        puts("No optimization needed");
    }
}

int main()
{
//    freopen("in.txt" , "r" , stdin);

    int T;
    scanf("%d" , &T);

    while(T--)
    {
        init();
        solve();
        if(T) putchar('\n');
    }

    return 0;
}