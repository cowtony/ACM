/*
验证哥德巴赫猜想，输入偶数4<=n<32768，输出有多少组质数和满足

用筛法及数组存下32768里哪些是质数
然后枚举搜索就行了

关键词：数学题，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    bool prime[32768];
    short n;
    int count;
    
    memset(prime,true,sizeof(prime));
    
    for(int i=2;i<=181;i++)
        for(int k=i+i;k<32768;k+=i)
            prime[k]=false;
            
    while(cin>>n)
    {
        if(n==0)break;
        if(n==4){cout<<1<<endl;continue;}
        count=0;
        for(int i=3;i<=n/2;i+=2)
            if(prime[i]==true&&prime[n-i]==true)count++;
            
        cout<<count<<endl;
    }
    
    //while(1);
    return 0;
}
