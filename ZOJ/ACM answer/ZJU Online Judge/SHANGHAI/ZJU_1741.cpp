#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[100];
int W[26][27];

void read_data()
{
    memset(W , 0xff , sizeof(W));
    
    char buf[100];
    
    while(1)
    {

        scanf("%s" , buf);
        if(strcmp(buf , "END_OF_FIRST_PART") == 0) break;
        if(buf[1] == 0)
            scanf("%d" , &W[buf[0] - 'A'][26]);
        else 
            scanf("%d" , &W[buf[0] - 'A'][buf[1] - 'a']);
    }
}

int find_left(int p)
{
    int cnt = 0;
    for(;;p--)
    {
        if(s[p] == ')') cnt++;
        else if(s[p] == '(') cnt--;    
        if(cnt == 0) return p;
    }
}

int Molecule(int p , int r)
{
    if(p > r) return 0;
    
    int w;
    if(isdigit(s[r]))
    {
        w = s[r--] - '0';        
        if(isdigit(s[r]))
        {
            w = (s[r--] - '0') * 10 + w;   
        }        
    }
    else w = 1;
    if(s[r] == ')')
    {
        int m = find_left(r);
        int left = Molecule(p , m - 1); if(left < 0) return -1;
        int right = Molecule(m + 1 , r - 1); if(right < 0) return -1;
        return left + right * w;
    }
    else
    {
        int curt;
        if(islower(s[r]))        
        {
            curt = W[s[r-1]-'A'][s[r]-'a'];                    
            r-=2;
        }
        else curt = W[s[r--]-'A'][26];
        
        if(curt < 0) return -1;
        int left = Molecule(p , r); if(left < 0) return -1;
        return curt * w + left;
    }
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    
    read_data();
    
    int ret;
    
    while(1)
    {
        scanf("%s" , s);
        if(strcmp(s , "0") == 0) break;
        ret = Molecule(0 , strlen(s) - 1);
        if(ret < 0) puts("UNKNOWN");
        else printf("%d\n" , Molecule(0 , strlen(s) - 1));
    }
    
    return 0;
}
