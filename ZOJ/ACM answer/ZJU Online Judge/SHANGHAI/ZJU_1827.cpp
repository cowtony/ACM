#include <stdio.h>
#include <string.h>

char s[100];
int f[5][5][5][5][5][5];

int k[8];

bool dp(int sum)
{    
    if(sum > 31) return 0;
    if(f[k[0]][k[1]][k[2]][k[3]][k[4]][k[5]] >= 0)
    {
        return f[k[0]][k[1]][k[2]][k[3]][k[4]][k[5]];
    }

    int *p = &f[k[0]][k[1]][k[2]][k[3]][k[4]][k[5]];

    *p = 0;
    for(int i=0; i<6; i++)
    {
        if(k[i] >= 4) continue;
        k[i]++;
        if(sum + i + 1 < 32 && !dp(sum + i + 1))
        {         
            *p = 1;
            k[i]--;
            break;
        }
        k[i]--;
    }
    return *p;
}

int main()
{
    memset(f , 0xff , sizeof(f));

    int i , len;
    int v;

    while(gets(s) > 0)
    {
        printf("%s " , s);
        len = strlen(s);
        memset(k , 0 , sizeof(k));
        for(v=i=0; i<len; i++)
        {
            v += s[i] - '0';
            k[s[i] - '1'] ++;
            if(v > 31)
            {
                if(len & 1) puts("A");
                else puts("B");
            }
        }

        if(i < len) continue;

        if(dp(v) != (len % 2 == 1)) puts("A");
        else puts("B");
    }

    return 0;
}