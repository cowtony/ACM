#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
bool X[10][10] , Y[10][10];

void Init()
{
    memset(X , 0 , sizeof(X));
    memset(Y , 0 , sizeof(Y));

    char s[10];
    int x , y;

    for(int i=0; i<n; i++)
    {
        scanf("%s%d%d" , s , &x , &y);
        if(s[0] == 'x') Y[x][y] = 1;
        else X[x][y] = 1;
    }
}

double x , y;
int id;

double dx[] = {0.25 ,  0.25 , -0.25 , -0.25};
double dy[] = {0.25 , -0.25 , -0.25 , 0.25};

bool mirror_exist(double x , double y)
{
    if(x == int(x))
    {
        return X[int(x)][int(y)];
    }
    if(y == int(y))
    {
        return Y[int(x)][int(y)];
    }
    return 0;
}

void mirror_operate(double x , double y , int& id)
{
    if(x == int(x))
    {
        if(id == 0) id = 3;
        else if(id == 1) id = 2;
        else if(id == 2) id = 1;
        else if(id == 3) id = 0;
    }
    else
    {
        if(id == 0) id = 1;
        else if(id == 1) id = 0;
        else if(id == 2) id = 3;
        else if(id == 3) id = 2;
    }
}

void Solve()
{
    x = 1; y = 0.5; id = 0;

    while(1)
    {
        if(x == 0.75 && y == 0.25)
        {
            puts("75 25");
            break;
        }
        if(mirror_exist(x , y))
        {
            mirror_operate(x , y , id);
        }
        else
        {
            if(x == 0 || x == 8 || y == 0 || y == 8)
            {
                printf("%d %d\n" , int(x * 100) , int(y * 100));
                break;
            }
        }
        x += dx[id];
        y += dy[id];
    }
}

int main()
{
//    freopen("in.txt" , "r" , stdin);

    while(1)
    {
        scanf("%d" , &n);
        if(n < 0) break;

        Init();
        Solve();
    }

//    system("pause");

    return 0;
}
