#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_cmp(const void* a , const void* b)
{
    return strcmp((char *)a , (char *)b);
}

int n;
char table[10010][20];
char s[20] , s0[20];

void Read_dict()
{
    n = 0;
    while(1)
    {
        scanf("%s" , s);
        if(s[0] == '#') break;
        strcpy(table[n++] , s);
    }
    qsort(table , n , sizeof(char)*20 , str_cmp);
}

bool find_word()
{
    int p , r , m;
    int ret;
    p = 0; r = n - 1;
    while(p <= r)
    {
        m = (p + r) / 2;
        ret = strcmp(s , table[m]);
        if(ret == 0) return 1;
        if(ret < 0) r = m - 1;
        else p = m + 1;
    }
    return 0;
}

char list[15*26*3][20];
int cnt;

void Work()
{
    while(1)    
    {
        memset(s , 0 , sizeof(s));
        scanf("%s" , s);
        if(s[0] == '#') break;

        if(find_word())
        {
            printf("%s is correct\n" , s);
        }
        else
        {
            printf("%s:" , s);
            cnt = 0;

            strcpy(s0 , s);
            
            int i , p , t;
            int len = strlen(s);
            //replace
            for(i=0; i<len; i++)
            {
                t = s[i];
                for(p='a'; p<='z'; p++)
                {
                    s[i] = p;
                    if(find_word())
                    {
                        strcpy(list[cnt++] , s);
                    }
                }
                s[i] = t;
            }

            //delete
            for(i=0; i<len; i++)
            {
                strcpy(s , s0);
                for(p=i; p<len; p++)
                    s[p] = s[p+1];
                if(find_word())
                {
                    strcpy(list[cnt++] , s);
                }
            }

            //insert
            for(i=0; i<=len; i++)
            {
                strcpy(s , s0);
                for(p=len; p>i; p--)
                    s[p] = s[p-1];
                for(p='a'; p<='z'; p++)
                {
                    s[i] = p;
                    if(find_word())
                    {
                        strcpy(list[cnt++] , s);
                    }
                }
            }

            qsort(list , cnt , sizeof(char)*20 , str_cmp);

            for(i=0; i<cnt; i++)
            {
                if(i == 0 || strcmp(list[i] , list[i-1]) != 0)
                {
                    printf(" %s" , list[i]);
                }
            }

            putchar('\n');
        }
    }
}

int main()
{
    //freopen("in.txt" , "r" , stdin);

    int T;
    scanf("%d" , &T);

    while(T--)
    {
        Read_dict();
        Work();
        if(T) putchar('\n');
    }
    
    return 0;
}