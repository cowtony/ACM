#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n;

short fest[370][16];

struct Stat
{
    short day;
    long long v;
};

bool operator < (const Stat& a , const Stat& b)
{
    if(a.day == b.day) return a.v < b.v;
    return a.day < b.day;    
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

inline int tstbit(long long& v , int p)
{
    return (v >> (p * 3)) & (long long)7;
}

inline void setbit(long long& v , int k , int p)
{
    v ^= (long long)tstbit(v , p) << (p * 3) ((long long)k << (p * 3));
}

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
        short x , y;
                
        for(i=0; i<9; i++)
        {
            next = curt;          
            x = tstbit(next.v , 16) + dx[i];
            y = tstbit(next.v , 17) + dy[i];
            
            if(x < 1 || y < 1 || x > 3 || y > 3) continue;
            if(!valid(x , y , next.day)) continue;

            for(p=0; p<16; p++)
            {
                setbit(next.v , tstbit(next.v , p) + 1 , p);
            }

            setbit(next.v , 0 , hash(x , y));
            setbit(next.v , 0 , hash(x-1 , y));
            setbit(next.v , 0 , hash(x , y-1));
            setbit(next.v , 0 , hash(x-1 , y-1));

            for(p=0; p<16; p++)
            {
                if(tstbit(next.v , p) > 6) break;
            }
            if(p == 16)
            {
                setbit(next.v , x , 16);
                setbit(next.v , y , 17);
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
        st.day = 1;
        st.v = 0;
        
        setbit(st.v , 2 , 16);
        setbit(st.v , 2 , 17);
        
        for(short i=0; i<16; i++)
        {
            setbit(st.v , 1 , i);
        }
        setbit(st.v , 0 , hash(2,2));
        setbit(st.v , 0 , hash(1,2));
        setbit(st.v , 0 , hash(2,1));
        setbit(st.v , 0 , hash(1,1));
        
        printf("%d\n" , search(st));
    }
}

int main()
{   
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout); 
    
    for(scanf("%d" , &n); n; scanf("%d" , &n))
    {
        init();
        solve();
    }
    return 0;
}


