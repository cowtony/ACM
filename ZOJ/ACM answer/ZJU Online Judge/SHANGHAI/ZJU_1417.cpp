#include <stdio.h>
#include <string.h>
#include <math.h>

struct point
{
    double x , y;
} list[250];

double G[250][250];
struct state
{
    int a , b , color;
} Q[110];             

int n , m , s[100] , K;
double F[40][250];

inline void read_point(point& p)
{
    scanf("%lf%lf" , &p.x , &p.y);
}

void Init()
{
    int i;
    read_point(list[0]);
    read_point(list[1]);
    K = 2;

    scanf("%d" , &n);

    for(i=1; i<=n; i++)
    {
        scanf("%d" , &s[i]);
    }

    scanf("%d" , &m);
    
    for(i=0; i<m; i++)
    {
        read_point(list[K]);
        read_point(list[K+1]);
        Q[i].a = K;
        Q[i].b = K + 1;
        K += 2;
        scanf("%d" , &Q[i].color);
    }
}

inline double dist(const point& a , const point& b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void Predoing()
{
    int i , j;
    for(i=0; i<K; i++)
    {
        for(j=i; j<K; j++)
            G[i][j] = G[j][i] = dist(list[i] , list[j]);        
    }
}

inline void renew(double& a , double b)
{
    if(b < a) a = b;
}

void Solve()
{
    int i , j , p;
    for(i=0; i<=n; i++)
        for(j=0; j<K; j++)
            F[i][j] = 1e20;
    F[0][0] = 0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<K; j++)
        {
            for(p=0; p<m; p++)
            {
                if(Q[p].color != s[i+1]) continue;
                renew(F[i+1][Q[p].b] , F[i][j] + G[j][Q[p].a] + G[Q[p].a][Q[p].b]);
                renew(F[i+1][Q[p].a] , F[i][j] + G[j][Q[p].b] + G[Q[p].a][Q[p].b]);
            }
        }
    }

    double min = 1e20;

    for(i=2; i<K; i++)
    {
        if(F[n][i] + G[1][i] < min)
            min = F[n][i] + G[1][i];
    }

    printf("%10.3lf\n" , min);
}

int main()
{
//    freopen("in.txt" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    
    int T;
    scanf("%d" , &T);

    while(T--)
    {
        Init();
        Predoing();
        Solve();
    }
    
    return 0;
} 
