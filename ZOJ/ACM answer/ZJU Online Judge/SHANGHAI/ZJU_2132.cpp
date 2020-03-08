#include <stdio.h>
#include <string.h>

int n;
int reco;
int cnt;

int main()
{
    int k;
    while(scanf("%d" , &n) > 0)
    {
        cnt = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d" , &k);
            if(cnt == 0) reco = k , cnt = 1;
            else if(k == reco) cnt++;
            else cnt--;
        }
        printf("%d\n" , reco);
    }
    return 0;
}