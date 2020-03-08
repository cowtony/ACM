#include <iostream>
#include <cstdio>

using namespace std;

int a[10005];
int min_last[2][10005];
long long min_sum[2][10005];

int n;

int main()
{
    int i,j,k,t1,t2,t3;
    scanf("%d",&n);
    for (i=0;i!=n;++i)
    {
        scanf("%d",&a[i]);
    }
    min_last[0][0]=a[0];
    min_sum[0][0]=a[0];
    min_last[0][1]=0;
    min_sum[0][1]=0;
    k=0;
    for (i=1;i!=n;++i)
    {
        memset(min_last[i%2],-1,sizeof(int)*(i+2));
        for (j=k;j!=i+1;++j)
        {
            if (min_last[(i+1)%2][j]!=-1)
            {
                min_last[i%2][j+1]=min_last[(i+1)%2][j]+1;
                min_sum[i%2][j+1]=min_sum[(i+1)%2][j]+min_last[i%2][j+1];
                if (a[i]>min_last[(i+1)%2][j] && (min_last[i%2][j]==-1 || a[i]<min_last[i%2][j])) 
                {
                    min_last[i%2][j]=a[i];
                    min_sum[i%2][j]=min_sum[(i+1)%2][j]+a[i];
                    if (j==k) --k;
                }
            }
        }
        ++k;
    }
    cout<<k<<" "<<min_sum[(i+1)%2][k]<<endl;
    return 0;
}