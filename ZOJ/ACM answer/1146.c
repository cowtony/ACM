#include <stdio.h>
#include <string.h>
int main()
{
    char a[23][106];
    int i,j;
    int s,t;
    char str[10];
    while(1)
    {
        scanf("%d %s",&s,str);
        if (s==0) break;
        for(i=0;i<23;i++)
        {
            for(j=0;j<106;j++)
            {
                a[i][j]='0';
            }
        }
        t=-1;
        for(i=0;i<strlen(str);i++)
        {
            switch(str[i])
            {
                case '1':
                {
                    for(j=1;j<=s;j++)
                    {
                        a[j][t+s+2]='1';
                        a[j+s+1][t+s+2]='1';
                    }
                    break;
                }
            case '2':
                {
                    for(j=t+2;j<t+2+s;j++)
                    {
                        a[0][j]='2';
                        a[s+1][j]='2';
                        a[2*s+2][j]='2';
                    }
                    for(j=1;j<s+1;j++)
                    {
                        a[j][t+s+2]='1';
                    }
                    for(j=s+2;j<2*s+2;j++)
                    {
                        a[j][t+1]='1';
                    }
                    break;
                }
            case '3':
                {
                    for(j=t+2;j<t+2+s;j++)
                    {
                        a[0][j]='2';
                        a[s+1][j]='2';
                        a[2*s+2][j]='2';
                    }
                    for(j=1;j<s+1;j++)
                    {
                        a[j][t+s+2]='1';
                        a[j+s+1][t+s+2]='1';
                    }
                }
                break;
            case '4':
                {
                    for(j=1;j<s+1;j++)
                    {
                        a[j][t+1]='1';
                        a[j][t+s+2]='1';
                        a[j+s+1][t+s+2]='1';
                    }
                    for(j=t+2;j<t+2+s;j++)
                    {
                        a[s+1][j]='2';
                    }
                    break;
                }
            case '5':
                {
                    for(j=t+2;j<t+2+s;j++)
                    {
                        a[0][j]='2';
                        a[s+1][j]='2';
                        a[2*s+2][j]='2';
                    }
                    for(j=1;j<s+1;j++)
                    {
                        a[j][t+1]='1';
                        a[j+s+1][t+s+2]='1';
                    }
                    break;
                }
            case '6':
                {
                    for(j=1;j<s+1;j++)
                    {
                        a[j][t+1]='1';
                        a[j+s+1][t+1]='1';
                        a[j+s+1][t+s+2]='1';
                    }
                    for(j=t+2;j<t+2+s;j++)
                    {
                        a[0][j]='2';
                        a[s+1][j]='2';
                        a[2*s+2][j]='2';
                    }
                    break;
                }
            case '7':
                {
                    for(j=1;j<s+1;j++)
                    {
                        a[j][t+s+2]='1';
                        a[j+s+1][t+s+2]='1';
                    }
                    for(j=t+2;j<t+2+s;j++)
                    {
                        a[0][j]='2';
                    }
                    break;
                }
            case '8':
                {
                    for(j=t+2;j<t+2+s;j++)
                    {
                        a[0][j]='2';
                        a[s+1][j]='2';
                        a[2*s+2][j]='2';
                    }
                    for(j=1;j<s+1;j++)
                    {
                        a[j][t+1]='1';
                        a[j][t+s+2]='1';
                        a[j+s+1][t+1]='1';
                        a[j+s+1][t+s+2]='1';
                    }
                    break;
                }
            case '9':
                {
                    for(j=t+2;j<t+2+s;j++)
                    {
                        a[0][j]='2';
                        a[s+1][j]='2';
                        a[2*s+2][j]='2';
                    }
                    for(j=1;j<s+1;j++)
                    {
                        a[j][t+1]='1';
                        a[j][t+s+2]='1';
                        a[j+s+1][t+s+2]='1';
                    }
                    break;
                }
            case '0':
                {
                    for(j=1;j<s+1;j++)
                    {
                        a[j][t+1]='1';
                        a[j][t+s+2]='1';
                        a[j+s+1][t+1]='1';
                        a[j+s+1][t+s+2]='1';
                    }
                    for(j=t+2;j<t+2+s;j++)
                    {
                        a[0][j]='2';
                        a[2*s+2][j]='2';
                    }
                    break;
                }
            default: break;
            }
            t+=(s+3);
        }
        for(i=0;i<2*s+3;i++)
        {
            for(j=0;j<t;j++)
            {
                if(a[i][j]=='1') printf("|");
                else if(a[i][j]=='2') printf("-");
                else printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
