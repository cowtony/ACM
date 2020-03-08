/*
输入n<=1000个整数（含负数），在这些数中找出最大的是其他三个数的和的数。

先由小到大快排，再用三个for循环遍历
i表示和，j,k,l表示剩余三个数
也可以用二分法，更快 

关键词：二分 
*/
#include<iostream>   
#include<algorithm>
using namespace std;

int main()   
{   
    int n;   
    long wager[1000];   
    bool flag;   
    while(cin>>n)
    {   
        if(n==0)return 0;
        
        flag=false;   
        for(int i=0;i<n;i++)cin>>wager[i];
    
        sort(wager,wager+n);  
         
        for(int i=n-1;i>0;i--)
        {   
            for(int j=n-1;j>=2;j--)   
            {   
                if(j==i)continue;   
                for(int k=j-1;k>=1;k--)   
                {   
                    if(k==i)continue;   
                    for(int l=k-1;l>=0;l--)   
                    {   
                        if(l==i)continue;   
                        if(wager[i]==wager[j]+wager[k]+wager[l])
                        {   
                            flag=true;   
                            cout<<wager[i]<<endl;
                            goto END;
                        }   
                    }   
                }   
            }   
        }   
        if(flag==false)cout<<"no solution"<<endl; 
        END:;
    }   
}  
