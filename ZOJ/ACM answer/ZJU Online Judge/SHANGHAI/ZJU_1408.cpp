#include <iostream>
#include <cstring>
using namespace std;

int k;
char s[100];
int A[100];

long double n;
unsigned long long N;

void Init()
{
    cin >> k;
    cin >> s;
    cin >> n;

    if(n < 0)
    {
        N = -n;
        for(int i=0; i<k; i++)
        {
            if(s[i] == 'n') s[i] = 'p';
            else s[i] = 'n';
        }
    }
    else N = n;
}

void Solve()
{
    int i , p , pp;

    memset(A , 0 , sizeof(A));

    for(i=0; i<k; i++)
    {
        A[i] = N % 2;
        N /= 2;
    }

    if(N)
    {
        cout << "Impossible" << endl;
        return;
    }

    for(i=0 , p = k - 1; i<k; i++ , p--)
    {
        if(A[i] && s[p] == 'n')
        {
            A[i + 1]++; pp = i + 1;
            while(A[pp] > 1)
            {
                A[pp] -= 2;
                A[++pp] ++;
            }
        }
        if(A[k])
        {
            cout << "Impossible" << endl; return;
        }
    }
    for(i=k-1; i>=0; i--)
    {
        cout << A[i];
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        Init();
        Solve();
    }

    return 0;
}
