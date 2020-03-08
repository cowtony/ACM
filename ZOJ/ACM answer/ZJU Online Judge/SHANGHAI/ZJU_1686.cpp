#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

int n;
int m , pm;

char city[110][20];
int s0 , s1;

struct edge
{
    int source , dest;
    int t0 , t1;
    int price;
} list[2010];

inline int find_name(char* s)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(strcmp(s , city[i]) == 0) return i;
    }
    strcpy(city[i] , s);
    n++;
    return i;    
}

void Init()
{
    char source[20] , dest[20];
    int a1 , a2 , b1 , b2 , a , b , price;
    char ch;

    pm = 0; n = 0;
    while(m--)
    {
        cin >> source >> a1 >> ch >> a2
            >> dest >> b1 >> ch >> b2
            >> price;
        a = a1 * 60 + a2;
        b = b1 * 60 + b2;

        if(a < 480 || b > 1080) continue;
        
        list[pm].source = find_name(source);
        list[pm].dest = find_name(dest);
        list[pm].t0 = a - 480;
        list[pm].t1 = b - 480;
        list[pm].price = price;
        pm++;
    }
    m = pm;
    s0 = find_name("Tokyo");
    s1 = find_name("Hakodate");    
}

bool time_inc(const edge& a , const edge& b)
{
    if(a.t1 != b.t1) return a.t1 < b.t1;
    return a.dest < b.dest;
}

bool time_dec(const edge& a , const edge& b)
{
    if(a.t0 != b.t0) return a.t0 > b.t0;
    return a.source < b.source;
}


int f00[110][700] , f10[110][700];
int f01[110][700] , f11[110][700];

inline int min(int a ,int b)
{
    return a < b ? a : b;
}

void dp0(int f[110][700] , int s)
{
    int t , i , j , p;

    for(i=0; i<n; i++)
        for(j=0; j<=600; j++)
            f[i][j] = 100000000;

    f[s][0] = 0; p = 0;

    for(t=1; t<=600; t++)
    {
        for(i=0; i<n; i++)
        {
            f[i][t] = f[i][t-1];
            while(p < m && list[p].t1 == t && list[p].dest == i)
            {
                f[i][t] = min(f[i][t] , f[list[p].source][list[p].t0] + list[p].price);
                p++;
            }
        }
    }
}

void dp1(int f[110][700] , int s)
{
    int t , i , j , p;

    for(i=0; i<n; i++)
        for(j=0; j<=600; j++)
            f[i][j] = 100000000;

    f[s][600] = 0; p = 0;

    for(t=599; t>=0; t--)
    {
        for(i=0; i<n; i++)
        {
            f[i][t] = f[i][t+1];
            while(p < m && list[p].t0 == t && list[p].source == i)
            {
                f[i][t] = min(f[i][t] , f[list[p].dest][list[p].t1] + list[p].price);
                p++;
            }
        }
    }
}

void Solve()
{
    sort(list , list + m , time_inc);
    dp0(f00 , s0);
    dp0(f10 , s1);

    sort(list , list + m , time_dec);
    dp1(f01 , s0);
    dp1(f11 , s1);

    int i , j , ret , tmp;
    ret = 100000000;
    for(i=0; i<n; i++)
    {
        for(j=0; j+30 <= 600; j++)
        {
            tmp = f00[i][j] + f10[i][j] + f01[i][j+30] + f11[i][j+30];
            if(tmp < ret) ret = tmp;            
        }
    }
    if(ret >= 100000000)
    {
        ret = 0;
    }
    cout << ret << endl;
}

int main()
{
    freopen("in.txt" , "r" , stdin);

    while(1)
    {
        cin >> m;
        if(!m) break;
        Init();
        Solve();
    }

    return 0;
} 
