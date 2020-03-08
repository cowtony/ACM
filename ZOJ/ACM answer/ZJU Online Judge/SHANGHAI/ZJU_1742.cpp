#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

struct Stat
{
    int c[4][8];
};

struct QType
{
    Stat s;
    int Len;
};

bool operator < (const Stat& a , const Stat& b)
{
    int i , j;
    for(i=0; i<4; i++)
        for(j=0; j<8; j++)
            if(a.c[i][j] != b.c[i][j]) return a.c[i][j] < b.c[i][j];
    return 0;
}

Stat st , dest;
set<Stat> MySet;
QType Q[100000];
int Head , Tail;

void init()
{
    int i , j;
    for(i=0; i<4; i++)
    {
        st.c[i][0] = 0;
        for(j=1; j<8; j++)
        {
            scanf("%d" , &st.c[i][j]);
        }
    }
}

inline void swap(int& a , int& b)
{
    int t = a; a = b; b = t;
}

inline bool push(QType a)
{
    if(memcmp(a.s.c , dest.c , sizeof(dest.c)) == 0)
    {
        printf("%d\n" , a.Len); return 1;
    }
    if(MySet.find(a.s) == MySet.end())
    {
        MySet.insert(a.s);
        Q[++Tail] = a;
    }
    return 0;
}

bool Process(QType a)
{
    int i , j , x , y;
    int k;
    for(i=0; i<4; i++)
    {
        for(j=1; j<8; j++)
        {
            if(a.s.c[i][j] == 0)
            {
                k = a.s.c[i][j - 1] + 1;
                if(k % 10 == 8) continue;
                for(x=0; x<4; x++)
                    for(y=1; y<8; y++)
                        if(k == a.s.c[x][y])
                        {
                            swap(a.s.c[i][j] , a.s.c[x][y]);
                            a.Len++;
                            if(push(a)) return 1;
                            swap(a.s.c[i][j] , a.s.c[x][y]);
                            a.Len--;
                            goto next;
                        }
                next :  ;
            }
        }
    }
    return 0;
}

void solve()
{
    // pre doing
    int i , j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<8; j++)
        {
            if(st.c[i][j] % 10 == 1)
            {
                swap(st.c[st.c[i][j] / 10 - 1][0] , st.c[i][j]);
            }
        }
    }
    
    // search
    MySet.clear();
    
    Head = 0; Tail = -1;
    
    QType curt;
    curt.s = st;
    curt.Len = 0;
    if(push(curt)) return;
    
    while(Head <= Tail)
    {
        if(Process(Q[Head++])) return;
    }
    puts("-1");
}

int main()
{
//    freopen("in.txt" , "r" , stdin);

    int i , j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<7; j++)
        {
            dest.c[i][j] = (i + 1) * 10 + j + 1;
        }
        dest.c[i][7] = 0;
    }
    
    int T;
    scanf("%d" , &T);    
       
    while(T--)
    {
        init();
        solve();
    }
    
    return 0;
}
