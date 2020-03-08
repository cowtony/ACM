#include<iostream>
#include<algorithm>
using namespace std;
//首先二分枚举第k大的值，然后遍历一遍boy，二分枚举girl，找到正好>=mid时的下标
//统计大于等于的个数，如果比k大，扩大枚举范围，反之缩小
//大二分套个循环再套个小二分即可，注意细节 
bool cmp(int x,int y){return x>y;}
int n,m;
int b[100005],g[100005];
int main()
{
    int i,j,k,t,l,r;
    long long left,right,mid,tmp,sum,ans,key;
    while(cin>>n>>m>>key)
    {
          for(i=1;i<=n;i++)scanf("%d",&b[i]);
          for(i=1;i<=m;i++)scanf("%d",&g[i]);
          
          sort(b+1,b+n+1,cmp);
          sort(g+1,g+m+1,cmp);
          
          left=1ll*b[n]*g[m];right=1ll*b[1]*g[1]; 
          ans=left;
          while(left<=right)//二分枚举第k大值 
          {
                mid=(left+right)/2;
                sum=0;
                for(i=1;i<=n;i++)//统计比mid大的个数 
                {
                    l=1;r=m;
                    t=0;
                    while(l<=r)
                    {
                          k=(l+r)/2;
                          if((1ll*b[i]*g[k])>=mid){t=k;l=k+1;}//太大了 
                          else r=k-1;//不够大     
                          }             
                    sum+=t;      
                    }
                if(sum>=key){ans=mid;left=mid+1;}
                else right=mid-1;                
                }                        
          cout<<ans<<endl;      
          }
    return 0;
    }
