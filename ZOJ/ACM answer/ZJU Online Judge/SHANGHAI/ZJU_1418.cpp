#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MOD 1739

char s[2][100];
int len[2];
int value[256];

void init(char s[] , int& len)
{
    len = 0;
    char ch = getchar();

    while(ch != '\n')
    {
        if(ch != ' ')
        {
            s[len++] = ch; 
        }
        ch = getchar();
    }
}

int find_right(int p , int idx)
{
    int cnt = 0;
    for(;;p++)
    {
        if(s[idx][p] == '(') cnt++;
        if(s[idx][p] == ')') cnt--;
        if(!cnt) return p;
    }
}

int find_op(int p , int r , int idx)
{
    int w = -1;
    int k = -1;
    int i;

    for(i=p; i<r; i++)
    {
        if(s[idx][i] == '(') i = find_right(i , idx);
        else
        {
            if(s[idx][i] == '+' || s[idx][i] == '-')
            {
                w = 100;
                k = i;
            }
            if(s[idx][i] == '*')
            {
                if(w < 0)
                {
                    w = 10;
                    k = i;
                }
            }
        }
    }
    return k;
}

int calc(int p , int r , int idx)
{
    if(p >= r) return 0;
    if(s[idx][p] == '(' && find_right(p , idx) + 1 == r)
    {
        return calc(p + 1 , r - 1 , idx);
    }

    int mid = find_op(p , r , idx);
    if(mid < 0)
    {
        if(isdigit(s[idx][p]))
        {
            int ret = 0;
            for(int i=p; i<r; i++)
                ret = ret * 10 + s[idx][i] - '0';
            return ret;
        }
        else return value[s[idx][p]];
    }

    int left = calc(p , mid , idx);
    int right = calc(mid + 1 , r , idx);
    int ret;

    if(s[idx][mid] == '+') ret = left + right;
    if(s[idx][mid] == '*') ret = left * right;
    if(s[idx][mid] == '-') ret = left - right;

    return ret % MOD;
}

void solve()
{
    int i , a , b;
    for(int T = 0; T < 5; T++)
    {
        for(i=0; i<256; i++)
        {
            value[i] = rand() % MOD;
        }
        a = (calc(0 , len[0] , 0) + MOD) % MOD;
        b = (calc(0 , len[1] , 1) + MOD) % MOD;
        if(a != b)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main()
{
    int T;
    char ch;

    scanf("%d" , &T);
    for(ch=getchar();ch!='\n';ch=getchar()){}

    srand(time(0));
    
    while(T--)
    {
        init(s[0] , len[0]);
        init(s[1] , len[1]);
        solve();
    }

    return 0;
} 
