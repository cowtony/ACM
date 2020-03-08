#include<iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int sequence[10002]={-1};
    for(int i=1;i<=n;i++)
        scanf("%d",sequence+i);
    sequence[n+1]=2000000001;
        
    int dp[10002]={1};
    long long min_sum[10002]={-1};
    
    for(int i=1;i<=n+1;i++)
    {
        if(sequence[i]>=i-1)
        {
            int max=0;
            for(int j=0;j<i;j++)
                if(sequence[i]-sequence[j]>=i-j)
                    if(dp[j]>max)max=dp[j];
            dp[i]=max+1;
            
            long long min=1e18;
            for(int j=0;j<i;j++)
            {
                if(dp[j]==max && sequence[i]-sequence[j]>=i-j)
                {
                    long long sum=min_sum[j]+sequence[i];
                    long long temp=i-j-1;
                    sum+=temp*(i-j)/2+temp*sequence[j];
                    if(min>sum)min=sum;
                }
            }
            min_sum[i]=min;
        }
    }
    
    
    /*
    for(int i=0;i<=n+1;i++)
        cout<<sequence[i]<<'\t';
    cout<<endl;
    for(int i=0;i<=n+1;i++)
        cout<<dp[i]<<'\t';
    cout<<endl;
    for(int i=0;i<=n+1;i++)
        cout<<min_sum[i]<<'\t';
    cout<<endl;
    */
    cout<<n-(dp[n+1]-2)<<' '<<min_sum[n+1]-2000000000;
    //while(1);
}
