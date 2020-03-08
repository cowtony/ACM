#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n;

short fest[370][16];

struct Stat
{
    short day;
    char x , y;
    char v[16];
};

bool operator < (const Stat& a , const Stat& b)
{
    if(a.day != b.day) return a.day < b.day;
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    for(short i=0; i<16; i++)
        if(a.v[i] != b.v[i]) return a.v[i] < b.v[i];
    return 0;
}

set<Stat> MySet;

void init()
{
    int i , j;
    for(i=0; i<n; i++)
        for(j=0; j<16; j++)
            scanf("%d" , &fest[i][j]);    
}

inline int hash(int x , int y)
{
    return (x << 2) + y;
}

inline bool valid(int x , int y , int day)
{
    return !fest[day][hash(x,y)] && !fest[day][hash(x-1,y)] && !fest[day][hash(x,y-1)]
        && !fest[day][hash(x-1,y-1)];
}

int dx[] = {1,2,-1,-2,0,0,0,0,0};
int dy[] = {0,0,0,0,0,1,2,-1,-2};

bool search(Stat curt)
{    
    if(curt.day == n)
    {
        return 1;
    }
    else
    {
        Stat next;
        short i , p;
        for(i=0; i<9; i++)
        {
            next = curt;            
            next.x += dx[i]; next.y += dy[i];
            if(next.x < 1 || next.y < 1 || next.x > 3 || next.y > 3) continue;
            if(!valid(next.x , next.y , next.day)) continue;
            for(p=0; p<16; p++)
            {
                next.v[p]++;
            }
            next.v[hash(next.x , next.y)] = 0;
            next.v[hash(next.x-1 , next.y)] = 0;
            next.v[hash(next.x , next.y-1)] = 0;
            next.v[hash(next.x-1 , next.y-1)] = 0;
            for(p=0; p<16; p++)
            {
                if(next.v[p] > 6) break;
            }
            if(p == 16)
            {
                next.day++;
                if(MySet.find(next) == MySet.end())
                {                    
                    MySet.insert(next);
                    if(search(next)) return 1;
                }
            }
        }
    }
    return 0;
}

void solve()
{
    if(!valid(2,2,0))
    {
        puts("0");
    }
    else
    {
        MySet.clear();
        Stat st;
        st.x = st.y = 2;
        st.day = 1;
        for(short i=0; i<16; i++)
            st.v[i] = 1;
        st.v[hash(2,2)] = st.v[hash(1,2)] = st.v[hash(2,1)] = st.v[hash(1,1)] = 0;
        printf("%d\n" , search(st));
    }
}

int main()
{
    freopen("in.txt" , "r" , stdin);

    for(scanf("%d" , &n); n; scanf("%d" , &n))
    {
        init();
        solve();
    }
    return 0;
}


