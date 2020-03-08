#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string line;
struct TRate
{
    int line;
    int k[110];
    int c[110][110];
    int Rank[110];
} R[2];

void Read_Rate(TRate& R)
{
    int i , p;
    int curt , next;
    cin >> R.line;

    memset(R.Rank , 0xff , sizeof(R.Rank));
    curt = next = 0;

    for(i=0; i<R.line; i++)
    {
        R.k[i] = 0;
        cin >> p;
        R.Rank[p] = curt , next++;
        R.c[i][R.k[i]++] = p;
        getline(cin , line);
        istringstream strin(line);

        while(strin >> p)
        {
            R.Rank[p] = curt , next++;
            R.c[i][R.k[i]++] = p;
        }
        curt = next;
    }
}

int Rank[110];
bool Undet[110];
struct TSort
{
    int idx;
    int value;
} list[110];
int m;

bool operator < (const TSort& a , const TSort& b)
{
    if(a.value == b.value) return a.idx < b.idx;
    return a.value < b.value;
}

int find_up_max(const TRate& R , int k)
{
    int ret = 0;
    int i , j;
    for(i=0; i<k; i++)
    {
        for(j=0; j<R.k[i]; j++)
            if(Rank[ R.c[i][j] ] >= 0 && Rank[ R.c[i][j] ] % 200 == 0)
            {
                if(Rank[ R.c[i][j] ] > ret) ret = Rank[ R.c[i][j] ];
            }
    }
    return ret;
}

int find_down_min(const TRate& R , int k)
{
    int ret = 10000000;
    int i , j;
    for(i=k+1; i<R.line; i++)
    {
        for(j=0; j<R.k[i]; j++)
            if(Rank[ R.c[i][j] ] >= 0 && Rank[ R.c[i][j] ] % 200 == 0)
            {
                if(Rank[ R.c[i][j] ] < ret) ret = Rank[ R.c[i][j] ];
            }
    }
    return ret;
}

void Solve()
{
    int i , j , k , p , cv;
    bool flag;
    memset(Rank , 0xff , sizeof(Rank));
    memset(Undet , 0 , sizeof(Undet));

    // The overall rating for the teams which took part in both contests    
    for(i=1; i<=100; i++)
    {
        if(R[0].Rank[i] >= 0 && R[1].Rank[i] >= 0)
        {
            Rank[i] = ( R[0].Rank[i] + R[1].Rank[i] ) * 200;
        }
    }

    // Rule A
    for(p=0; p<2; p++)
    {
        for(i=0; i<R[p].line; i++)
        {
            flag = 0; cv = -1;
            for(j=0; j<R[p].k[i]; j++)
            {
                if(Rank[ R[p].c[i][j] ] >= 0)
                {
                    cv = Rank[ R[p].c[i][j] ];
                    for(k=j+1; k<R[p].k[i]; k++)
                        if(Rank[ R[p].c[i][k] ] >= 0)
                        {
                            if(Rank[ R[p].c[i][j] ] != Rank[ R[p].c[i][k] ])
                            {
                                flag = 1;
                                break;
                            }
                        }                    
                    if(flag) break;
                }
            }

            for(k=0; k<R[p].k[i]; k++)
            {
                if(Rank[ R[p].c[i][k] ] >= 0) continue;
                if(flag) Undet[ R[p].c[i][k] ] = 1;
                else Rank[ R[p].c[i][k] ] = cv;
            }
        }
    }

    // Rule B

    int up_max;
    int down_min;

    for(p=0; p<2; p++)
    {
        for(i=0; i<R[p].line; i++)
        {
            // find_up_max
            up_max = find_up_max(R[p] , i);
            // find_down_min
            down_min = find_down_min(R[p] , i);

            if(up_max >= down_min)
            {
                for(k=0; k<R[p].k[i]; k++)
                {
                    if(Rank[ R[p].c[i][k] ] >= 0 || Undet[ R[p].c[i][k] ]) continue;
                    Undet[ R[p].c[i][k] ] = 1;
                }
            }
            else
            {
                for(k=0; k<R[p].k[i]; k++)
                {
                    if(Rank[ R[p].c[i][k] ] >= 0 || Undet[ R[p].c[i][k] ]) continue;
                    Rank[ R[p].c[i][k] ] = up_max + R[p].Rank[ R[p].c[i][k] ] + 1;
                }
            }
        }
    }

    m = 0;
    for(i=1; i<=100; i++)
    {
        if(Rank[i] < 0 || Undet[i]) continue;
        list[m].idx = i;
        list[m].value = Rank[i];
        m++;
    }

    sort(list , list + m);

    for(i=0; i<m; )
    {
        cout << list[i].idx;
        i++;
        while(i < m && list[i].value == list[i-1].value)
        {
            cout << " " << list[i].idx;
            i++;
        }
        cout << endl;
    }
}

int main()
{
    freopen("in.txt" , "r" , stdin);

    int T;
    cin >> T;

    while(T--)
    {
        Read_Rate(R[0]);
        Read_Rate(R[1]);
        Solve();

        if(T) cout << endl;
    }
    return 0;
}