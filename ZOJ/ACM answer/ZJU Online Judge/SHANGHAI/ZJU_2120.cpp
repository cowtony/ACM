#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[100];
int n;
int f[100][5][5][3];
int pa[100][5][5][3];
int pb[100][5][5][3];
int pc[100][5][5][3];

inline int TYPE(char ch)
{
    if(ch == '.') return 0;
    if(ch == 'U') return 1;
    if(ch == 'L') return 2;
    if(ch == 'D') return 3;
    if(ch == 'R') return 4;
}

inline int cost(int st , int ed)
{
    if(st == ed) return 3;
    if(st == 0 || ed == 0) return 5;    
    if(abs(st - ed) == 2) return 7;
    return 5;
}

inline void renew(int p , int l , int r , int x , int p0 , int a , int b , int c , int cost)
{
    cost += f[p0][a][b][c];
    if(cost < f[p][l][r][x])
    {
        f[p][l][r][x] = cost;
        pa[p][l][r][x] = a;
        pb[p][l][r][x] = b;
        pc[p][l][r][x] = c;
    }
}

void step(int p , int target)
{
    int left , right , x , y;
    for(left=0; left<5; left++)
        for(right=0; right<5; right++)
        {
            if(left == 4 && right == 2) continue;
            for(x=0; x<=2; x++)
            {
                if(left == target)
                {
                    //if(right==2) continue;                                                
                    if(x == 1) renew(p+1,left,right,1,p,left,right,x,3);
                    else renew(p+1,left,right,1,p,left,right,x,1);
                }
                else if(right == target)
                {                    
                    //if(left==4) continue; 
                    if(x == 2) renew(p+1,left,right,2,p,left,right,x,3);
                    else renew(p+1,left,right,2,p,left,right,x,1);
                }
                else
                {
                    for(y=1; y<=2; y++)
                    {
                        if(right==2 && y==1) continue;                        
                        if(left==4 && y==2) continue;                        
                        
                        if(y==1 && (cost(left,target)!=7 || right!=0)) 
                        {
                            if(!(target == 4 && right == 0 && left == 0))
                            renew(p+1,target,right,y,p,left,right,x, (y==x)?cost(left,target):1);
                        }
                        if(y==2 && (cost(right,target)!=7 || left!=0))
                        {
                            if(!(target == 2 && left == 0 && right == 0))
                            renew(p+1,left,target,y,p,left,right,x, (y==x)?cost(right,target):1);
                        }
                    }
                }
            }
        }    
}

void print_path(int p , int left , int right , int x)
{
    if(p)
    {
        print_path(p - 1 , pa[p][left][right][x] , pb[p][left][right][x] , pc[p][left][right][x]);

        if(x == 0) putchar('.');
        else if(x == 1) putchar('L');
        else putchar('R');
    }
}

void solve()
{
    int i , left , right , p , x;
    
    for(i=0; i<=n; i++)
    {
        for(left=0; left<5; left++)
            for(right=0; right<5; right++)
                for(x=0; x<=2; x++)
                    f[i][left][right][x] = 10000000;
    }
    memset(pa , 0 , sizeof(pa));
    memset(pb , 0 , sizeof(pb));
    memset(pc , 0 , sizeof(pc));

    f[0][0][0][0] = 0;
    for(i=1; i<=n; i++)
    {
        if(s[i-1] == '.')
        {
            for(left=0; left<5; left++)
                for(right=0; right<5; right++)
                {
                    if(left == 4 && right == 2) continue;
                    for(p=0; p<=2; p++)
                    {
                        renew(i,left,right,0,i-1,left,right,p,0);
                        //renew(i,left,right,p,i-1,left,right,p,0);
                    }
                }

            step(i - 1 , 0);
            step(i - 1 , 1);
            step(i - 1 , 2);
            step(i - 1 , 3);
            step(i - 1 , 4);
        }
        else
        {
            step(i - 1 , TYPE(s[i-1]));
        }
    }

    int min = 10000000;
    int L , R , X;
    for(left=0; left<5; left++)
        for(right=0; right<5; right++)
        {
            if(right == 2 && left == 4) continue;
            for(x=0; x<=2; x++)
            {
                if(min >= f[n][left][right][x])
                {
                    min = f[n][left][right][x];
                    L = left;
                    R = right;
                    X = x;
                }
            }
        }
    
    //printf("%d\n" , min);
    print_path(n , L , R , X);
    putchar('\n');
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    while(1)
    {
        scanf("%s" , s);        
        n = strlen(s);        
        if(s[0] == '#') break;        
        
        solve();
    }

    return 0;
}

