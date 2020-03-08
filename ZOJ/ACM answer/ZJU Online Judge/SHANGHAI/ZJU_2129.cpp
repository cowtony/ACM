#include <stdio.h>
#include <string.h>

int n;
char g[30][30];
short stat[100][100][101][2];
int CaseNo;

void init()
{
    for(int i=0; i<=2*n; i++)
        gets(g[i]);
}

struct point
{
    char x , y;
};

struct TQ
{
    point body;
    point m1 , m2;
    bool m2_exist;
    bool gate;
    int len;
} Q[100 * 100 * 100 * 2 + 100];
int Head , Tail;

inline void push(const TQ& a)
{    
    if(stat[a.body.x*10+a.body.y][a.m1.x*10+a.m1.y][a.m2_exist ? (a.m2.x*10+a.m2.y) : 100][a.gate] < CaseNo)
    {
        stat[a.body.x*10+a.body.y][a.m1.x*10+a.m1.y][a.m2_exist ? (a.m2.x*10+a.m2.y) : 100][a.gate] = CaseNo;
        Q[++Tail] = a;
    }
}

int dx[] = {0 , 1 , -1 , 0 , 0 };
int dy[] = {0 , 0 , 0  , 1 , -1};

inline bool invalid(point& p)
{
    return p.x < 0 || p.y < 0 || p.x >= n || p.y >= n;
}

inline bool pass(int x , int y , int dx , int dy , bool gate)
{
    if(g[x*2+1+dx][y*2+1+dy] == ' ') return 1;
    if(g[x*2+1+dx][y*2+1+dy] == 'G' && gate == 0) return 1;
    return 0;
}

void make_step(TQ& a , bool gate)
{
    //先水平，后垂直
    short dx , dy;
    if(a.m1.x == a.body.x) dx = 0;
    if(a.m1.x < a.body.x) dx = 1;
    if(a.m1.x > a.body.x) dx = -1;

    if(a.m1.y == a.body.y) dy = 0;
    if(a.m1.y < a.body.y) dy = 1;
    if(a.m1.y > a.body.y) dy = -1;

    if(a.m1.y == a.body.y || (!pass(a.m1.x , a.m1.y , 0 , dy , gate)))
    {        
        if(a.m1.x != a.body.x)
        {
            //垂直 (dx , 0)
            if(pass(a.m1.x , a.m1.y , dx , 0 , gate))
            {
                a.m1.x += dx;
                if(g[a.m1.x * 2 + 1][a.m1.y * 2 + 1] == 'K') a.gate = !a.gate;
            }
        }
    }
    else
    {
        //水平 (0 , dy)
        if(pass(a.m1.x , a.m1.y , 0 , dy , gate))
        {
            a.m1.y += dy;
            if(g[a.m1.x * 2 + 1][a.m1.y * 2 + 1] == 'K') a.gate = !a.gate;
        }        
    }    

    if(a.m2_exist)
    {
        if(a.m2.x == a.body.x) dx = 0;
        if(a.m2.x < a.body.x) dx = 1;
        if(a.m2.x > a.body.x) dx = -1;

        if(a.m2.y == a.body.y) dy = 0;
        if(a.m2.y < a.body.y) dy = 1;
        if(a.m2.y > a.body.y) dy = -1;

        if(a.m2.y == a.body.y || (!pass(a.m2.x , a.m2.y , 0 , dy , gate)))
        {        
            if(a.m2.x != a.body.x)
            {
                //垂直 (dx , 0)
                if(pass(a.m2.x , a.m2.y , dx , 0 , gate))
                {
                    a.m2.x += dx;
                    if(g[a.m2.x * 2 + 1][a.m2.y * 2 + 1] == 'K') a.gate = !a.gate;
                }
            }
        }
        else
        {
            //水平 (0 , dy)
            if(pass(a.m2.x , a.m2.y , 0 , dy , gate))
            {
                a.m2.y += dy;
                if(g[a.m2.x * 2 + 1][a.m2.y * 2 + 1] == 'K') a.gate = !a.gate;
            }        
        }
        
        if(a.m1.x == a.m2.x && a.m1.y == a.m2.y) a.m2_exist = 0;
    }
}

TQ curt;

int p;
bool flag;

bool process(const TQ& a)
{
    
    for(int i=0; i<5; i++)
    {
        curt = a;
        curt.len++;

        if(i != 0)
            if(!pass(curt.body.x , curt.body.y , dx[i] , dy[i] , curt.gate)) continue;
        
        curt.body.x += dx[i];
        curt.body.y += dy[i];
        if(invalid(curt.body))
        {
            printf("%d\n" , a.len);
            return 1;
        }

        if(g[curt.body.x*2+1][curt.body.y*2+1]=='K' && (dx[i] != 0 || dy[i] != 0))
            curt.gate = !curt.gate;

        flag = 1;
        
        ////////////////////
        for(p=0; p<2; p++)
        {
            make_step(curt , curt.gate);
            if(curt.m1.x == curt.body.x && curt.m1.y == curt.body.y)
            {
                flag = 0;
                break;
            }
            if(curt.m2_exist && curt.m2.x == curt.body.x && curt.m2.y == curt.body.y)
            {
                flag = 0;
                break;
            }
        }
        ////////////////////

        if(flag) push(curt);
    }
    return 0;
}

void solve()
{
    TQ st;
    st.m2_exist = 0;
    st.gate = 1;

    bool m1 = 0;
    
    int i , j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(g[i*2+1][j*2+1] == 'E') 
            {
                st.body.x = i;
                st.body.y = j;
            }
            if(g[i*2+1][j*2+1] == 'M')
            {
                if(m1)
                {
                    st.m2_exist = 1;
                    st.m2.x = i;
                    st.m2.y = j;
                }
                else
                {
                    st.m1.x = i;
                    st.m1.y = j;
                    m1 = 1;
                }
            }
        }
    st.len = 0;
    
    Head = 0; Tail = -1;
    push(st);
    
    while(Head <= Tail)
    {
        if(process(Q[Head++]))
        {
            return;
        }
    }

    puts("-1");
}

int main()
{
//    freopen("in.txt" , "r" , stdin);

    CaseNo = 0;
    while(scanf("%d" , &n) > 0)
    {
        ++CaseNo;
        getchar();
        init();
        solve();
    }
    return 0;
}